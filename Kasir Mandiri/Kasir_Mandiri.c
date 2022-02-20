#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct identitas{
	char nama [100];
	int antrian; 
};
struct proses{
    int kode, harga, bayar, kembalian, i, total_harga, jml_pesanan, diskon, harga_akhir, metode_pembayaran;
    unsigned int uang_kurang;
	char ker;
};

struct identitas c;
struct proses g;

void awal(void){
    puts("\t\t\t========================================");
    puts("\t\t\t||          TOKO KUE CENDANA          ||");
    puts("\t\t\t||         KUE KHAS INDONESIA	      ||"); 
    puts("\t\t\t||      JALAN PETOGOGAN 1 NOMOR 19    ||");
    puts("\t\t\t========================================");
    puts("-------------------------------------------------------------------------------------");
}

void promo (void){
	printf("[ INFO PROMO ]\n\n");
	printf("1. DISKON 10 PERSEN UNTUK PEMBAYARAN VIA GOPAY, DENGAN MINIMUM BELANJA Rp. 100.000\n");
	printf("2. BELANJA DIATAS Rp. 50.000 MENDAPAT 1 KUE LAPIS\n");
	printf("3. BELANJA DIATAS Rp. 100.000 MENDAPAT 2 KUE LAPIS\n");
	printf("4. BELANJA DIATAS Rp. 150.000 MENDAPAT 3 KUE LAPIS\n");
	printf("5. BELANJA DIATAS Rp. 200.000 MENDAPAT 4 KUE LAPIS\n");
	printf("-------------------------------------------------------------------------------------\n");
}

void identitas(struct identitas a){
	printf("\t\t\t[--STRUK PEMBELIAN TOKO KUE CENDANA--]\n");
	printf("\t\t[--JALAN PETOGOGAN 1 NOMOR 19, KUE KHAS INDONESIA--]\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("[ INFORMASI PELANGGAN ]\n\n");
	printf("Nama\t\t: %s\n", a.nama);
	printf("No. Antrian\t: %d\n", a.antrian);
}

void menu (void){
	printf("[ MENU KUE TOKO CENDANA ]\n");
	printf("\n--------------------------------------------------------");
	printf("\n|Kode |         Menu			|      Harga   |");
	printf("\n--------------------------------------------------------");
	printf("\n| 1.  | Kue Lapis			|   Rp. 5000   |");
	printf("\n| 2.  | Kue Apem			|   Rp. 7000   |");
	printf("\n| 3.  | Kue Talam			|   Rp. 6000   |");
	printf("\n| 4.  | Kue Bugis			|   Rp. 9000   |");
	printf("\n| 5.  | Kue Putu 			|   Rp. 7500   |");
	printf("\n| 6.  | Kue Sari			|   Rp. 6500   |");
	printf("\n| 7.  | Kue Naga			|   Rp. 7000   |");
	printf("\n--------------------------------------------------------\n\n");

	printf("-------------------------------------------------------------------------------------\n");
}

void pilihmenu(void){
	printf("[ PILIH MENU (MENGGUNAKAN KODE) ]\n\n");
}

void metodepembayaran (void){
	printf("[ PILIH METODE PEMBAYARAN ]\n\n");
    printf("1. GOPAY\n");
    printf("2. OVO\n");
    printf("3. SHOPEEPAY\n");
    printf("4. DANA\n");
    printf("5. ATM\n");
    printf("SELAIN 1-5 --> TUNAI\n\n");
}

void akhir(void){
	puts("\t\t\t========================================");
    puts("\t\t\t||            TERIMA KASIH            ||");
    puts("\t\t\t||     SEMOGA HARIMU MENYENANGKAN     ||"); 
    puts("\t\t\t========================================");
}

int main()
{   
	awal();
	g.ker='y';
	g.total_harga = 0;
	g.i = 1;
	
	time_t current_time;
	time(&current_time);
	
	struct tm *waktu = localtime(&current_time);
	
	promo();
	
	printf("[ KETIK NAMA PELANGGAN & NO. ANTRIAN ]\n\n");
	printf("Masukkan nama \t: ");
	gets(c.nama);
	printf("Nomor antrian \t: ");
	scanf("%d", &c.antrian );
	
	system("cls");
	identitas(c);
	printf ( "Tanggal input \t: %d / %d / %d, Jam = %d : %d : %d\n", waktu->tm_mday, waktu->tm_mon+1, waktu->tm_year + 1900, waktu->tm_hour, waktu->tm_min, waktu->tm_sec);
	printf("-------------------------------------------------------------------------------------\n");
	
	menu();
	pilihmenu();

	while (g.ker=='y')
{
		printf("Kue ke - %d \t: ", g.i);
		scanf("%d", &g.kode);
		fflush (stdin);
		
	if(g.kode==1)
	{
	g.harga = 5000;
	printf("Harga Kue Lapis : Rp. %d\n", g.harga);
	}
		else if (g.kode==2)
		{
			g.harga = 7000;
			printf("Harga Kue Apem \t: Rp. %d\n", g.harga); 
		}
		else if (g.kode==3)
		{
			g.harga = 6000;
			printf("Harga Kue Talam : Rp. %d\n", g.harga); 
		}
		else if (g.kode==4)
		{
			g.harga = 9000;
			printf("Harga Kue Bugis : Rp. %d\n", g.harga);
		}
		else if (g.kode==5)
		{
			g.harga = 7500;
			printf("Harga Kue Apem \t: Rp. %d\n", g.harga);
		}
		else if (g.kode==6)
		{
			g.harga = 6500;
			printf("Harga Kue Sari \t: Rp. %d\n", g.harga);
		}
		else if (g.kode==7)
		{
			g.harga = 7000;
			printf("Harga Kue Naga \t: Rp. %d\n", g.harga);
		}
	else
	{
	printf("Input anda salah!!!");
	g.harga = 0;
	}
printf("\n");
g.total_harga = g.total_harga + g.harga;
printf("\n");
printf("Ketik 'y' untuk melanjutkan pesanan, Ketik huruf SELAIN 'y' untuk masuk ke pembayaran : ");
scanf("%c", &g.ker);
g.i++;


}
printf("-------------------------------------------------------------------------------------\n");
metodepembayaran();
printf("PILIH METODE PEMBAYARAN (MENGGUNAKAN KODE)\t : ");
scanf("%d", &g.metode_pembayaran);

	switch(g.metode_pembayaran){
		case 1:
			if(g.total_harga >= 100000)
			{
			g.diskon = (g.total_harga * 0.1);
			printf("METODE PEMBAYARAN\t\t\t\t : GOPAY\n");
			}
			else
			{
			g.diskon = 0;
			printf("METODE PEMBAYARAN\t\t\t\t : GOPAY\n");
			}
			break;
		case 2:
		g.diskon = 0;
		printf("METODE PEMBAYARAN\t\t\t\t : OVO\n");
		break;

		case 3:
		g.diskon = 0;
		printf("METODE PEMBAYARAN\t\t\t\t : SHOPEEPAY\n");
		break;

		case 4:
		g.diskon = 0;
		printf("METODE PEMBAYARAN\t\t\t\t : DANA\n");
		break;

		case 5:
		g.diskon = 0;
		printf("METODE PEMBAYARAN\t\t\t\t : ATM\n");
		break;

		default:
		g.diskon = 0;
		printf("METODE PEMBAYARAN\t\t\t\t : TUNAI\n");
		break;
	}

g.harga_akhir = g.total_harga - g.diskon;

printf("-------------------------------------------------------------------------------------\n");
printf("\tTOTAL HARGA PEMBELIAN\t\t\t\t : Rp. %d\n", g.total_harga);
printf("\tDISKON\t\t\t\t\t\t : Rp. %d\n", g.diskon);
printf("\tHARGA YANG HARUS DIBAYARKAN\t\t\t : Rp. %d\n", g.harga_akhir);

printf("\tMASUKKAN NOMINAL UANG YANG ANDA BAYARKAN\t : Rp. ", g.bayar );
	
	scanf("%d", &g.bayar);	
	g.kembalian = g.bayar - g.harga_akhir;
	g.uang_kurang = g.harga_akhir - g.bayar;
	
	
	if(g.bayar>g.harga_akhir)
	{
		printf("\tUANG KEMBALIAN ANDA\t\t\t\t : Rp. %d\n\n ", g.kembalian);
	}
	else if(g.bayar == g.harga_akhir)
	{
		printf("\n");
		printf("\t\t\t\t[ UANG ANDA PAS ]\n");
	}
	else
	{
		printf("\tUANG ANDA KURANG\t\t\t\t : Rp. %d\n\n ", g.uang_kurang);	
	}
	
	if(g.total_harga >= 50000 && g.total_harga < 100000)
	{
		if(g.bayar >= g.total_harga || g.bayar >= g.harga_akhir )
		{
		printf("\t\t\tSELAMAT ANDA MENDAPATKAN BONUS 1 KUE LAPIS\n");
		}
		else
		printf(" ");
	}
	else if (g.total_harga >= 100000 && g.total_harga < 150000 )
	{
		if(g.bayar >= g.total_harga || g.bayar >= g.harga_akhir)
		{
		printf("\t\t\tSELAMAT ANDA MENDAPATKAN BONUS 2 KUE LAPIS\n");
		}
		else
		printf(" ");
	}
	else if (g.total_harga >= 150000 && g.total_harga < 200000)
	{
		if(g.bayar >= g.total_harga || g.bayar >= g.harga_akhir)
		{
		printf("\t\t\tSELAMAT ANDA MENDAPATKAN BONUS 3 KUE LAPIS\n");
		}
		else
		printf(" ");
	}
	else if (g.total_harga >= 200000)
	{
		if(g.bayar >= g.total_harga || g.bayar >= g.harga_akhir)
		{
		printf("\t\t\tSELAMAT ANDA MENDAPATKAN BONUS 4 KUE LAPIS\n");
		}
		else
		printf(" ");
	}
	else
	{
		if(g.total_harga >= g.bayar || g.bayar >= g.harga_akhir )
		{
		printf(" ");
		}
		else
		printf("\tANDA TIDAK MENDAPATKAN BONUS\n");
	}
printf("\n");
printf("-------------------------------------------------------------------------------------\n");

	if (g.bayar >= g.harga_akhir)
	{
		printf("\t\t\t\t||TRANSAKSI SUKSES||\n");
	}
	else
	{
		printf("\t\t\t\t||TRANSAKSI GAGAL||\n");
	}

printf("-------------------------------------------------------------------------------------\n");
akhir();
printf("-------------------------------------------------------------------------------------\n");
system("pause");
return 0;
}
