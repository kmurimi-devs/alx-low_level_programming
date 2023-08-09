#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd;
    Elf64_Ehdr header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error");
        return 2;
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        perror("Error");
        close(fd);
        return 3;
    }

    if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' || header.e_ident[2] != 'L' || header.e_ident[3] != 'F') {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 4;
    }

    printf("ELF Header:\n");
    printf(" Magic:");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf(" %02x", header.e_ident[i]);
    }
    printf("\n");

    printf(" Class: ");
    switch (header.e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
    }

    printf(" Data: ");
    switch (header.e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
    }

    printf(" Version: %d", header.e_ident[EI_VERSION]);
    if (header.e_ident[EI_VERSION] == EV_CURRENT) {
        printf(" (current)\n");
    } else {
        printf("\n");
    }

    printf(" OS/ABI: ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone App\n");
            break;
        default:
            printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
    }

    printf(" ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

    printf(" Type: ");
    if (header.e_ident[EI_DATA] == ELFDATA2MSB) {
        header.e_type >>= 8;
    }
    switch (header.e_type) {
        case ET_NONE:
            printf("NONE (None)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", header.e_type);
    }

    printf(" Entry point address: ");
    if (header.e_ident[EI_DATA] == ELFDATA2MSB) {
        header.e_entry = ((header.e_entry << 8) & 0xFF00FF00) | ((header.e_entry >> 8) & 0xFF00FF);
        header.e_entry = (header.e_entry << 16) | (header.e_entry >> 16);
    }
    if (header.e_ident[EI_CLASS] == ELFCLASS32) {
        printf("%#x\n", (unsigned int)header.e_entry);
    } else {
        printf("%#lx\n", header.e_entry);
    }

    close(fd);
    return 0;
}
