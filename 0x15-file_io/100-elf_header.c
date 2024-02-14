#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

void print_elf_header(Elf64_Ehdr *hdr) {
    const char *magic = "ELF";
    const char *class_str[] = { "none", "ELF32", "ELF64" };
    const char *data_str[] = { "none", "2's complement, little endian", "2's complement, big endian" };
    const char *osabi_str[] = { "UNIX System V", "HP-UX", "NetBSD", "GNU/Linux", "GNU/Hurd", "86Open", "Solaris", "AIX", "IRIX", "FreeBSD", "Tru64", "Novell Modesto", "OpenBSD", "OpenVMS", "NonStop Kernel", "AROS", "FenixOS", "CloudABI" };
    const char *type_str[] = { "none", "Relocatable file", "Executable file", "Shared object file", "Core file" };

    printf("Magic:   %c%c%c\n", magic[0], magic[1], magic[2]);
    printf("Class:   %s\n", class_str[hdr->e_ident[EI_CLASS]]);
    printf("Data:    %s\n", data_str[hdr->e_ident[EI_DATA]]);
    printf("Version: %d\n", hdr->e_ident[EI_VERSION]);
    printf("OS/ABI:  %s\n", osabi_str[hdr->e_ident[EI_OSABI]]);
    printf("ABI Ver: %d\n", hdr->e_ident[EI_ABIVERSION]);
    printf("Type:    %s\n", type_str[hdr->e_type]);
    printf("Entry:   0x%lx\n", hdr->e_entry);
}

int open_elf_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error(strerror(errno));
        exit(98);
    }
    return fd;
}

Elf64_Ehdr *read_elf_header(int fd) 
{
	char buf[BUF_SIZE];
	Elf64_Ehdr *hdr = (Elf64_Ehdr *)buf;
	ssize_t nread = read(fd, buf, sizeof(buf));
	
	if (nread == -1) {
        print_error(strerror(errno));
        exit(98);
    }
    if (strncmp((const char *)hdr->e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
        exit(98);
    }
    return hdr;
}

void skip_elf_sections(int fd, Elf64_Ehdr *hdr) 
{
	char buf[BUF_SIZE];
	ssize_t nread = read(fd, buf, sizeof(buf));
    if (lseek(fd, (off_t)hdr->e_shoff, SEEK_SET) == -1) {
        print_error(strerror(errno));
        exit(98);
    }
    if (nread == -1) {
        print_error(strerror(errno));
        exit(98);
    }
}

int main(int argc, char **argv) 
{
	int fd = open_elf_file(argv[1]);
	 Elf64_Ehdr *hdr = read_elf_header(fd);

    if (argc != 2) 
    {
        print_error("Usage: elf_header elf_filename");
        exit(98);
    }
    print_elf_header(hdr);
    skip_elf_sections(fd, hdr);

    close(fd);
    return 0;
}
