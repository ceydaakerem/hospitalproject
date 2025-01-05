#include <stdio.h>
#include <stdlib.h>

int hesapla_yol_suresi(int secilenpoliklinik);

int main() {
    int sayi, polikliniksecim, doktorsecim;
    int i;

    const char* poliklinikler[] = { "Plastik Cerrahi", "Dahiliye", "KBB", "Kardiyoloji" };
    const char* doktorlar[4][4] = {
        {"Dr Ahmet", "Dr Mehmet", "Dr Ali", "Dr Ceyda"}, // Plastik Cerrahi doktorları
        {"Dr Veli", "Dr Hasan", "Dr Hakan", "Dr Arda"}, // Dahiliye doktorları
        {"Dr Sema", "Dr Murat", "Dr Emine", "Dr Fatma"}, // KBB doktorları
        {"Dr Kemal", "Dr Harun", "Dr Can", "Dr Furkan"}  // Kardiyoloji doktorları
    };

   
    FILE *dosya = fopen("secimler.txt", "w");  // Dosyayı yazma modunda açıyoruz.
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;  // Dosya açılamazsa programı sonlandır
    }

    while (1) {
        printf("Hastane Konum Bulma Sistemine Hosgeldiniz\n");
        printf("Lutfen gitmek istediginiz birimi seciniz:\n");
        printf("1 - Poliklinik\n2 - Kantin\n3 - Otopark\n4 - Acil\n");
        scanf("%d", &sayi);

        // Kullanıcı seçimlerini dosyaya kaydediyor
        fprintf(dosya, "Kullanici Secimi: %d\n", sayi);  

        if (sayi == 1) {
            printf("Hangi poliklinige gitmek istediginizi seciniz:\n");
            for (i = 0; i < 4; i++) 
			{
                printf("%d - %s\n", i + 1, poliklinikler[i]);
            }
            scanf("%d", &polikliniksecim);

            fprintf(dosya, "Secilen Poliklinik: %s\n", poliklinikler[polikliniksecim - 1]);

            if (polikliniksecim >= 1 && polikliniksecim <= 4) {
                printf("%s poliklinigindeki hangi doktoru secmek istersiniz?\n", poliklinikler[polikliniksecim - 1]);
                for ( i = 0; i < 4; i++) {
                    printf("%d - %s\n", i + 1, doktorlar[polikliniksecim - 1][i]);
                }
                scanf("%d", &doktorsecim);

                fprintf(dosya, "Secilen Doktor: %s\n", doktorlar[polikliniksecim - 1][doktorsecim - 1]);

                if (doktorsecim >= 1 && doktorsecim <= 4) {
                    printf("Sectiginiz doktor: %s\n", doktorlar[polikliniksecim - 1][doktorsecim - 1]);
                    int sure = hesapla_yol_suresi(sayi);
                    printf("Gitmeniz gereken yere: %d dakikada ulaabilirsiniz.\n", sure);
                    fprintf(dosya, "Ulasim Sure: %d dakika\n", sure);
                }
                else {
                    printf("Gecersiz doktor secimi.\n");
                }
            }
            else {
                printf("Gecersiz poliklinik secimi.\n");
            }
        }

        if (sayi == 2) {
            printf("Kantine gitmek icin bu adimlari takip ediniz.\n");
            int sure = hesapla_yol_suresi(sayi);
            printf("Gitmeniz gereken yere: %d dakikada ulaabilirsiniz.\n", sure);
            fprintf(dosya, "Secilen Konum: Kantin\n");
            fprintf(dosya, "Ulasim Sure: %d dakika\n", sure);
        }
        if (sayi == 3) {
            printf("Otoparka gitmek icin bu adimlari takip ediniz.\n");
            int sure = hesapla_yol_suresi(sayi);
            printf("Gitmeniz gereken yere: %d dakikada ulaabilirsiniz.\n", sure);
            fprintf(dosya, "Secilen Konum: Otopark\n");
            fprintf(dosya, "Ulasim Sure: %d dakika\n", sure);
        }
        if (sayi == 4) {
            printf("Acil servise gitmek icin bu adimlari takip ediniz.\n");
            int sure = hesapla_yol_suresi(sayi);
            printf("Gitmeniz gereken yere: %d dakikada ulaabilirsiniz.\n", sure);
            fprintf(dosya, "Secilen Konum: Acil\n");
            fprintf(dosya, "Ulasim Sure: %d dakika\n", sure);
        }

        printf("\n===============================\n\n");
    }

    fclose(dosya);  // Dosyayı kapatıyor

    return 0;
}

int hesapla_yol_suresi(int secilenpoliklinik) {
    int sureler[] = { 10, 5, 15, 3 };
    return sureler[secilenpoliklinik - 1];  // Seçilen polikliniğe göre süreyi döndürüyoruz
}
