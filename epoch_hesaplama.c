#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgilerini saklamak için bir yapı
struct TarihSaat {
    int yil;
    int ay;
    int gun;
    int saat;
    int dakika;
    int saniye;
};

// Tarih ve saat bilgilerini okuyup bir TarihSaat yapısına dönüştürme
void tarihSaatOku(struct TarihSaat *ts) {
    printf("Yil (YYYY): ");
    scanf("%d", &ts->yil);
    printf("Ay (MM): ");
    scanf("%d", &ts->ay);
    printf("Gun (DD): ");
    scanf("%d", &ts->gun);
    printf("Saat (HH): ");
    scanf("%d", &ts->saat);
    printf("Dakika (MM): ");
    scanf("%d", &ts->dakika);
    printf("Saniye (SS): ");
    scanf("%d", &ts->saniye);
}

// TarihSaat yapısını epoch zamana dönüştürme
time_t epochZamaninaCevir(struct TarihSaat ts) {
    struct tm t;
    t.tm_year = ts.yil - 1900; // tm_year: 1900'dan bu yana geçen yıllar
    t.tm_mon = ts.ay - 1;      // tm_mon: 0-11 arası (0: Ocak, 11: Aralık)
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    t.tm_isdst = -1; // Gün ışığından yararlanma saatini otomatik olarak belirle

    return mktime(&t);
}

int main() {
    struct TarihSaat baslangicZamani, bitisZamani;

    // İlk tarih ve saat bilgisini oku
    printf("Baslangic tarih ve saati giriniz:\n");
    tarihSaatOku(&baslangicZamani);

    // İkinci tarih ve saat bilgisini oku
    printf("Bitis tarih ve saati giriniz:\n");
    tarihSaatOku(&bitisZamani);

    // Epoch zamanlarına dönüştür
    time_t baslangicEpoch = epochZamaninaCevir(baslangicZamani);
    time_t bitisEpoch = epochZamaninaCevir(bitisZamani);

    // Zaman farkını hesapla
    double fark = difftime(bitisEpoch, baslangicEpoch);

    // Sonuçları ekrana yazdırır
    printf("\nBaslangic epoch zamani: %ld\n", (long)baslangicEpoch);
    printf("Bitis epoch zamani: %ld\n", (long)bitisEpoch);
    printf("Zaman farki (saniye): %.0f\n", fark);

    return 0;
}
