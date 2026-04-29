#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char kategori[50];
    int tahun;
    int nilai;
} artefak;

// Fungsi untuk membandingkan dua artefak berdasarkan aturan prioritas
// Mengembalikan nilai < 0 jika artefak A lebih baik dari B
int compare_artefak(artefak a, artefak b) {
    if (a.nilai != b.nilai) {
        return b.nilai - a.nilai; // nilai lebih tinggi lebih baik (diatas)
    }
    if (a.tahun != b.tahun) {
        return a.tahun - b.tahun; // tahun lebih kecil diatas
    }
    return strcmp(a.name, b.name); // Nama alfabetis lebih awal lebih baik
    return strcmp(a.kategori, b.kategori); // kategori dengan alfabetis lebih awal lebih baik
}

int main() {
    int n;
    
    // Membaca jumlah data artefak
    if (scanf("%d", &n) != 1) return 0;

    // Alokasi memori dinamis untuk menyimpan data artefak
    artefak *artfk = (artefak *)malloc(n * sizeof(artefak));
    
    // Membaca input setiap artefak
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d", artfk[i].name, artfk[i].kategori, &artfk[i].tahun, &artfk[i].nilai);
    }

    // Mencari dan mencetak penjaga terbaik untuk setiap nama artefak
    for (int i = 0; i < n; i++) {
        artefak best_artefak;
        int found = 0;

        for (int i = 0; i < n; i++) {
            // Jika ini artefak pertama yang ditemukan atau lebih baik dari yang terbaik sejauh ini
            if (!found || compare_artefak(artfk[i], best_artefak) < 0) {
                best_artefak = artfk[i++];
                found = 1;
                
            }
        }

        // Mencetak hasil sesuai format
        if (found) {
            printf("%s %s %d %d\n", best_artefak.name, best_artefak.kategori, best_artefak.tahun, best_artefak.nilai);
        } else {
            printf("-\n");
        }
    }

    // Bebaskan memori
    free(artfk);
    return 0;
}
