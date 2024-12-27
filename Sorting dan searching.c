#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100

// Struktur untuk menyimpan data mahasiswa
typedef struct {
    char nama[50];
    char nim[10];
    int nilai;
} Mahasiswa;

// Fungsi untuk membandingkan dua mahasiswa berdasarkan nilai
int compare_nilai(const void *a, const void *b) {
    Mahasiswa *mhsA = (Mahasiswa *)a;
    Mahasiswa *mhsB = (Mahasiswa *)b;
    return mhsA->nilai - mhsB->nilai; // Urutkan dari yang terkecil ke terbesar
}

// Fungsi untuk membandingkan dua mahasiswa berdasarkan NIM
int compare_nim(const void *a, const void *b) {
    Mahasiswa *mhsA = (Mahasiswa *)a;
    Mahasiswa *mhsB = (Mahasiswa *)b;
    return strcmp(mhsA->nim, mhsB->nim); // Urutkan berdasarkan NIM
}

// Fungsi untuk membandingkan dua mahasiswa berdasarkan nama
int compare_nama(const void *a, const void *b) {
    Mahasiswa *mhsA = (Mahasiswa *)a;
    Mahasiswa *mhsB = (Mahasiswa *)b;
    return strcmp(mhsA->nama, mhsB->nama); // Urutkan berdasarkan nama
}

// Fungsi untuk mencari mahasiswa berdasarkan nilai
void search_by_nilai(Mahasiswa mahasiswa[], int jumlah_mahasiswa, int nilai_cari) {
    int found = 0; // Variabel untuk mengecek apakah ada mahasiswa yang ditemukan
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (mahasiswa[i].nilai == nilai_cari) {
            if (!found) {
                printf("Mahasiswa dengan nilai %d ditemukan:\n", nilai_cari);
                found = 1; // Tandai bahwa setidaknya satu mahasiswa telah ditemukan
            }
            printf("Nama: %s, NIM: %s, Nilai: %d\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].nilai);
        }
    }
    if (!found) {
        printf("Tidak ada mahasiswa dengan nilai %d ditemukan.\n", nilai_cari);
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
int search_by_nim(Mahasiswa mahasiswa[], int jumlah_mahasiswa, const char* nim_cari) {
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (strcmp(mahasiswa[i].nim, nim_cari) == 0) {
            return i; // Kembalikan indeks mahasiswa yang ditemukan
        }
    }
    return -1; // Jika tidak ditemukan
}

// Fungsi utama
int main() {
    Mahasiswa mahasiswa[MAX_MAHASISWA] = {
 {"Alden Putra", "23010087", 70},
        {"Aldo Pramudya", "23010011", 73},
        {"Aldo Putra", "23010047", 75},
        {"Aldrian Saputra", "23010091", 78},
        {"Andi Prasetyo", "23010020", 80},
        {"Bella Citra", "23010055", 81},
        {"Bella Sari", "23010035", 82},
        {"Budi Kurniawan", "23010023", 84},
        {"Budi Santoso", "23010029", 85},
        {"Cahya Putra", "23010002", 86},
        {"Cesar Irawan", "23010027", 87},
        {"Citra Anggraini", "23010018", 88},
        {"Citra Dewi", "23010090", 89},
        {"Dewi Lestari", "23010040", 90},
        {"Dika Aditya", "23010088", 91},
        {"Dika Ramadhan", "23010025", 92},
        {"Dina Rahma", "23010077", 93},
        {"Eko Prasetyo", "23010081", 94},
        {"Eko Setiawan", "23010051", 95},
        {"Eko Susanto", "23010015", 96},
        {"Eva Lestari", "23010024", 97},
        {"Fajar Hidayat", "23010079", 98},
        {"Fani Lestari", "23010098", 99},
        {"Fani Rahmawati", "23010089", 70},
        {"Ferry Hidayat", "23010014", 72},
        {"Gilang Nurhadi", "23010062", 74},
        {"Gilang Prabowo", "23010053", 76},
        {"Gita Melati", "23010044", 77},
        {"Gita Wulandari", "23010078", 79},
        {"Hanafi Ahmad", "23010099", 80},
        {"Hanafi Maulana", "23010030", 82},
        {"Hendra Gunawan", "23010039", 83},
        {"Hendra Wijaya", "23010076", 84},
        {"Ika Permadi", "23010073", 85},
        {"Ika Permata", "23010063", 86},
        {"Ika Salsabila", "23010005", 87},
        {"Indra Permana", "23010036", 88},
        {"Joko Prabowo", "23010095", 89},
        {"Joko Santoso","23010006" ,90 },
        {"Joni Prabowo", "23010031", 91},
        {"Joni Setyawan", "23010084", 92},
        {"Kania Ayu", "23010072", 93},
        {"Kania Kusuma", "23010070", 94},
        {"Kiki Amalia", "23010009", 95},
        {"Kiki Nuraini", "23010048", 96},
        {"Lila Rahmawati", "23010032", 97},
        {"Linda Ayu", "23010060", 98},
        {"Luki Adi", "23010058", 99},
        {"Lukman Hakim", "23010092", 70},
        {"Miko Ramadhan", "23010026", 72},
        {"Miko Setiawan", "23010097", 74},
        {"Mira Anindita", "23010042", 76},
        {"Mira Fitria", "23010085", 78},
        {"Nadia Rachmawati", "23010064", 79},
        {"Nanda Rizki", "23010007", 80},
        {"Nia Kurnia", "23010041", 81},
        {"Nia Sari","23010100" ,82 },
        {"Oka Santoso","23010052" ,83 },
        {"Oki Saputra","23010012" ,85 },
        {"Oky Putu Gede", "23010054", 86},
        {"Omar Fadhil", "23010013", 87},
        {"Omar Farok", "23010004", 89},
        {"Pesta Anggraini", "23010043", 90},
        {"Poppy Anindita", "23010061", 91},
        {"Putri Anindita", "23010069", 92},
        {"Putu Widi", "23010046", 93},
        {"Qaisara Aulia", "23010086", 94},
        {"Qolbu Aulia", "23010059", 96},
        {"Qori Alif", "23010017", 97},
        {"Quebeck Azril", "23010068", 98},
        {"Razan Akbar", "23010066", 99},
        {"Rizal Akbar", "23010033", 70},
        {"Rudi Hartono", "23010093", 71},
        {"Rudi Hermanto", "23010001", 73},
        {"Sari Marito", "23010003", 75},
        {"Sari Melati", "23010034", 76},
        {"Siti Khadijah", "23010019", 78},
        {"Siti Nabila", "23010096", 79},
        {"Tariq Ramadhan", "23010067", 80},
         {"Taufik Ramadhan", "23010080", 81},
        {"Tono Kroos", "23010028", 82},
        {"Tono Setyawan", "23010022", 84},
        {"Uli Margaret", "23010016", 86},
        {"Uli Pramudita", "23010049", 88},
        {"Umar Faruq", "23010083", 89},
        {"Vina Kasper", "23010045", 91},
        {"Vina Lestari", "23010038", 92},
        {"Vivi Anisa", "23010082", 93},
        {"Wira Catur", "23010074", 94},
        {"Wira Prasetya", "23010037", 95},
        {"Wira Saputra", "23010008", 97},
        {"Xena Kamilah", "23010071", 98},
        {"Xena Lilith", "23010075", 99},
        {"Xena Puspita", "23010065", 70},
        {"Yudas Sanji", "23010021", 80},
        {"Yudi Setiawan", "23010056", 87},
        {"Yusuf Abdurrahman", "23010094", 88},
        {"Zahra Nabila", "23010010", 97},
        {"Zainab Rahmawati", "23010057", 95},
        {"Zayn Malik","23010050" ,79 }

    };

    int jumlah_mahasiswa = sizeof(mahasiswa) / sizeof(mahasiswa[0]); // Menghitung jumlah mahasiswa
    int pilihan;

    // Menampilkan data mahasiswa sebelum diurutkan
    printf("Mahasiswa sebelum diurutkan:\n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
         printf("Nama: %s, NIM: %s, Nilai: %d\n",
                mahasiswa[i].nama,
                mahasiswa[i].nim,
                mahasiswa[i].nilai);
     }

     // Meminta pilihan pengurutan dari pengguna
     printf("\nPilih kriteria pengurutan:\n");
     printf("1. Berdasarkan Nilai\n");
     printf("2. Berdasarkan NIM\n");
     printf("3. Berdasarkan Nama\n");
     printf("4. Pencarian Berdasarkan Nilai\n"); // Opsi pencarian baru
     printf("5. Pencarian Berdasarkan NIM\n");   // Opsi pencarian berdasarkan NIM
     printf("Pilihan Anda (1/2/3/4/5): ");
     scanf("%d",&pilihan);

     if (pilihan == 1) {
         qsort(mahasiswa, jumlah_mahasiswa, sizeof(Mahasiswa), compare_nilai);
         printf("\nMahasiswa setelah diurutkan berdasarkan nilai:\n");
     } else if (pilihan == 2) {
         qsort(mahasiswa, jumlah_mahasiswa, sizeof(Mahasiswa), compare_nim);
         printf("\nMahasiswa setelah diurutkan berdasarkan NIM:\n");
     } else if (pilihan == 3) {
         qsort(mahasiswa, jumlah_mahasiswa, sizeof(Mahasiswa), compare_nama);
         printf("\nMahasiswa setelah diurutkan berdasarkan nama:\n");
     } else if (pilihan == 4) { // Pilihan untuk pencarian berdasarkan nilai
         int nilai_cari;
         printf("Masukkan nilai yang ingin dicari: ");
         scanf("%d",&nilai_cari);
         
         search_by_nilai(mahasiswa, jumlah_mahasiswa, nilai_cari); // Memanggil fungsi pencarian yang diperbarui
         return 0; // Keluar setelah pencarian
     } else if (pilihan == 5) { // Pilihan untuk pencarian berdasarkan NIM
         char nim_cari[10];
         printf("Masukkan NIM yang ingin dicari: ");
         scanf("%s",&nim_cari);
         
         int index = search_by_nim(mahasiswa, jumlah_mahasiswa, nim_cari);
         if (index != -1) {
             printf("Mahasiswa dengan NIM %s ditemukan:\n",
                    nim_cari);
             printf("Nama: %s, NIM: %s, Nilai: %d\n",
                    mahasiswa[index].nama,
                    mahasiswa[index].nim,
                    mahasiswa[index].nilai);
         } else {
             printf("Mahasiswa dengan NIM %s tidak ditemukan.\n",
                    nim_cari);
         }
         return 0; // Keluar setelah pencarian
     } else {
         printf("Pilihan tidak valid!\n");
         return 1; // Menghentikan program jika pilihan tidak valid
     }

     // Menampilkan hasil pengurutan
     for (int i = 0; i < jumlah_mahasiswa; i++) {
         printf("Nama: %s, NIM: %s, Nilai: %d\n",
                mahasiswa[i].nama,
                mahasiswa[i].nim,
                mahasiswa[i].nilai);
     }

     return 0;
}
