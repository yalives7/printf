#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
int my_putchar(char c) {
    return write(1, &c, 1);  // Tek bir karakteri yazdır ve yazdırılan karakter sayısını döndür
}

int my_putstr(const char *str) {
    int count = 0;
    while (*str) {
        count += write(1, str, 1);  // Her bir karakteri yazdır ve sayacı artır
        str++;
    }
    return count;  // Yazdırılan karakter sayısını döndür
}

int my_putnbr(int n) {
    int count = 0;
    
    if (n == 0) {
        count += my_putchar('0');  // 0'ı yazdır ve sayacı artır
        return count;
    }
    
    if (n < 0) {
        count += my_putchar('-');  // Negatif işareti yazdır ve sayacı artır
        n = -n;  // Negatif sayıyı pozitif yap
    }

    // Recurse for the number
    if (n / 10) {
        count += my_putnbr(n / 10);  // Kendisini çağırarak sayıyı yazdır
    }

    count += my_putchar((n % 10) + '0');  // Son basamağı yazdır ve sayacı artır
    return count;
}

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    const char *ptr = format;
    int total_count = 0;  // Yazdırılan toplam karakter sayısını tutacak

    while (*ptr) {
        if (*ptr == '%' && *(ptr + 1)) {  // Format spesifier bul
            ptr++;  // % işaretini geç
            switch (*ptr) {
                case 'd': {  // Tam sayı (integer)
                    int i = va_arg(args, int);
                    total_count += my_putnbr(i);  // Sayıyı yazdır ve sayacı artır
                    break;
                }
                case 's': {  // String
                    char *s = va_arg(args, char*);
                    total_count += my_putstr(s);  // Stringi yazdır ve sayacı artır
                    break;
                }
                case 'c': {  // Karakter
                    char c = (char)va_arg(args, int);
                    total_count += my_putchar(c);  // Karakteri yazdır ve sayacı artır
                    break;
                }
                default:
                    total_count += my_putchar('%');
                    total_count += my_putchar(*ptr);  // Tanınmayan format spesifier'ı yazdır
                    break;
            }
        } else {
            total_count += my_putchar(*ptr);  // Normal karakterleri olduğu gibi yazdır
        }
        ptr++;
    }

    va_end(args);
    return total_count;  // Yazdırılan toplam karakter sayısını döndür
}

int main() {
    int num = 42;
    char *str = "Hello, world!";
    char c = 'A';

    int printed = my_printf("Integer: %d\n", num);
    my_printf("String: %s\n", str);
    my_printf("Character: %c\n", c);
    my_printf("Total characters printed: %d\n", printed);  // Yazdırılan toplam karakter sayısını yazdır
    int a = my_printf("eheh");
    printf("%d",a);
    return 0;
}
