#include <stdio.h>

struct Araba {
    char marka[50];
    char model[50];
    float yuzde100YakitTuketimi;
    float mevcutYakit;
    int mevcutKm;
};

void arabaBilgileriniAl(struct Araba araba[], int arabaNo) {
    printf("Arabanın markasını girin: ");
    scanf("%s", araba[arabaNo].marka);
    printf("Arabanın modelini girin: ");
    scanf("%s", araba[arabaNo].model);
    printf("100 kilometredeki yakit tuketimini (litre/100 km) girin: ");
    scanf("%f", &araba[arabaNo].yuzde100YakitTuketimi);
    printf("Arabadaki mevcut yakiti girin (litre): ");
    scanf("%f", &araba[arabaNo].mevcutYakit);
    printf("Arabanın mevcut kilometresini girin: ");
    scanf("%d", &araba[arabaNo].mevcutKm);
}

float yakitHesapla(struct Araba araba, int hedefKm) {
    int mesafe = hedefKm - araba.mevcutKm;
    float gerekenYakit = (mesafe / 100.0) * araba.yuzde100YakitTuketimi;
    return gerekenYakit;
}

void yakitDurumunuKontrolEt(struct Araba araba) {
    int hedefKm;
    printf("Bir sonraki hedef kilometreyi girin: ");
    scanf("%d", &hedefKm);

    float gerekenYakit = yakitHesapla(araba, hedefKm);
    printf("Hedef kilometreye ulaşmak için gereken yakit: %.2f litre\n", gerekenYakit);

    if (araba.mevcutYakit >= gerekenYakit) {
        printf("Yeterli yakıtınız var, kalan yakıt: %.2f litre\n", araba.mevcutYakit - gerekenYakit);
    } else {
        printf("Yeterli yakıtınız yok, eksik yakıt: %.2f litre\n", gerekenYakit - araba.mevcutYakit);
    }

    float yuzde100Yakit = yakitHesapla(araba, araba.mevcutKm + 100);
    printf("100 kilometrede harcanacak yakıt: %.2f litre\n", yuzde100Yakit);
}

void bakimZamaniHesapla(struct Araba araba) {
    int sonBakimKm;
    printf("Son bakım yapılan kilometreyi girin: ");
    scanf("%d", &sonBakimKm);

    int fark = araba.mevcutKm - sonBakimKm;
    if (fark >= 10000) {
        printf("Bakım zamanı gelmiş. En kısa sürede bakım yaptırın.\n");
    } else {
        printf("Bakım için kalan kilometre: %d\n", 10000 - fark);
    }
}

int main() {
    int arabaSayisi, secim;

    printf("Kaç adet araba gireceksiniz? ");
    scanf("%d", &arabaSayisi);

    struct Araba arabalar[arabaSayisi];

    for (int i = 0; i < arabaSayisi; i++) {
        printf("\n--- %d. Araba ---\n", i + 1);
        arabaBilgileriniAl(arabalar, i);

        printf("Seçim yapın:\n1. Yakıt durumu kontrolü\n2. Bakım zamanı hesaplama\nSeçiminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                yakitDurumunuKontrolEt(arabalar[i]);
                break;
            case 2:
                bakimZamaniHesapla(arabalar[i]);
                break;
            default:
                printf("Geçersiz seçim.\n");
        }
    }

    return 0;
}