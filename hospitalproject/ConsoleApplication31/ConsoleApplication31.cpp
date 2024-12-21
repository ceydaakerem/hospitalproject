#include <stdio.h>
#include <stdlib.h>

int main() {
    int sayi, polikliniksecim, doktorsecim;


    const char* poliklinikler[] = { "Plastik Cerrahi", "Dahiliye", "KBB", "Kardiyoloji" };
    const char* doktorlar[4][4] = {
        {"Dr Ahmet", "Dr Mehmet", "Dr Ali", "Dr Ceyda"}, // Plastik Cerrahi doktorları//
        {"Dr Veli", "Dr Hasan", "Dr Hakan", "Dr Arda"}, // Dahiliye doktorları//
        {"Dr Sema", "Dr Murat", "Dr Emine", "Dr Fatma"}, // KBB doktorları//
        {"Dr Kemal", "Dr Harun", "Dr Can", "Dr Furkan"} // Kardiyoloji doktorları//
    };

    printf("Hastane Konum Bulma Sistemine Hosgeldiniz\n");
    printf("Lutfen gitmek istediginiz birimi seciniz:\n");
    printf("1 - Poliklinik\n2 - Kantin\n3 - Otopark\n4 - Acil\n");
    scanf_s("%d", &sayi);

    if (sayi == 1) {
        printf("Hangi poliklinige gitmek istediginizi seciniz:\n");
        for (int i = 0; i < 4; i++) {
            printf("%d - %s\n", i + 1, poliklinikler[i]); //char dizisine ait olduğu için s kullandım//
        }
        scanf_s("%d", &polikliniksecim);

        if (polikliniksecim >= 1 && polikliniksecim <= 4) {
            printf("%s poliklinigindeki hangi doktoru secmek istersiniz?\n", poliklinikler[polikliniksecim - 1]);
            for (int i = 0; i < 4; i++) {
                printf("%d - %s\n", i + 1, doktorlar[polikliniksecim - 1][i]);
            }
            scanf_s("%d", &doktorsecim);
            if (doktorsecim >= 1 && doktorsecim <= 4) {
                printf("sectiginiz doktor: %s gitmeniz gereken yol\n", doktorlar[polikliniksecim - 1][doktorsecim - 1]);
            }
            else {
                printf("gecersiz doktor secimi.\n");
            }
        }
        else {
            printf("gecersiz poliklinik secimi.\n");
        }
    }

    if (sayi == 2) {
        printf("kantine gitmek icin bu adimlari takip ediniz.\n");
    }
    if (sayi == 3) {
        printf("otoparka gitmek icin bu adimlari takip ediniz.\n");
    }
    if (sayi == 4) {
        printf("acil servise gitmek icin bu adimlari takip ediniz.\n");
    }
    return 0;
}

