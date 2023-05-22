#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//
int x=3;
char cari[100];
//menu admin
	struct{
		char judul[50],kategori[50],sinopsis[100];
		int tahunrilis;
	}buku;

//regis member
char username[99],pass[99];//login member
struct akunmember{
	char namamember[99];
	char kelasmember[99];
	int usia;
	char institusi[99];
	char usernamemember[99];
	char passmember[99];	
}member;


//REGISMEMBER
FILE*f_regismember;
FILE*f_regismember2;

//BUKU
FILE*listbuku;
FILE*listbuku2;

int main(){
	int pilih;
	printf("SIAPAKAH ANDA ?\n");
	printf("1. Admin\n");
	printf("2. Member\n");
	printf("Masukan jawaban(angka):");
	scanf("%d",&pilih);
	getchar();
	switch(pilih){
		case 1 : system("cls"); 
		printf("===ANDA AKAN DIALIHKAN MENUJU LOGIN ADMIN===");
		system("cls"); loginadmin();break;
		
		case 2 :system("cls"); menuregis();break;
		default :  system("cls");
				printf("\nMenu yang anda pilih tidak tersedia\nsilahkan mengisi ulang nomor menu \n\n");
				printf("klik enter agar dapat memilih menu\n\n");
				system("pause");
				main();break;
	}
	return 0;
}

int loginadmin()
{ //ini adalah halaman login admin
	char adminid[99],adminpass[99];
	int x=3,y;
	char usernameadmin,passadmin;
	system("cls");
	printf("=====HALAMAN LOGIN ADMIN=====\n");
	printf("Masukan username dan password\n");
	fflush(stdin);
	printf("Username : ");
	gets(adminid);
	printf("Password : ");
	gets(adminpass);
	
	if(x>0){
	if(strcmp(adminid,"Perpus")==0 && strcmp(adminpass,"Mantap")==0)
	{ 
	y=1;
	}
	
	if(y==1){
		printf("LOGIN SUKSES\n");
		printf("===Klik enter agar Dialihkan ke Menu Admin===");
		printf("\n\n");
		system("PAUSE\n");system("cls");
	menuadmin();
	}
	
	else
	{
		printf("\nLogin Gagal, Silahkan Mencoba Kembali!\n\n");
		x--;
		system("PAUSE");system("cls");
    	loginadmin();
}
}
	else{
		printf("Login gagal");
	
	}
}

int menuregis(){//menu utama
	int pilih;
	system("cls");
	printf("====SELAMAT DATANG DI MENU REGISTRASI====\n");
	printf("silahkan pilih menu yang anda inginkan\n\n");
	printf("1. Registrasi Member");
	printf("\n2. Login Member");
	printf("\n3. EXIT");

	printf("\n\nPilih Nomor menu yang anda inginkan : ");
	scanf("%d",&pilih);
	switch(pilih){ 
		case 1 : registrasimember();break;
		case 2 : loginmember();break;
		case 3 : system("cls");
				printf("\n\nAnda akan kembali ke menu utama\n");
				system("pause"); system("cls"); main();break;
		
		default : system("cls");
				printf("\nMenu yang anda pilih tidak tersedia\nsilahkan mengisi ulang nomor menu \n\n");
				printf("klik enter agar dapat memilih menu\n\n");
				system("pause");
				menuregis();break;
				
	}
	
	return 0;
}

int registrasimember(){
	int i,n;
	f_regismember = fopen("regisakunmember.dat","ab"); 

		printf("====REGISTRASI MEMBER====\n");
		printf("\nMasukan Nama : ");
		fflush(stdin);
		gets(member.namamember);
		printf("\nMasukan Kelas: ");
		gets(member.kelasmember);
		printf("\nMasukan Usia : ");
		scanf("%d",&member.usia);getchar();	
		printf("\nMasukan Institusi : "); 
		gets(member.institusi);
	
	
		printf("\n\n=Masukan username dan password==\n");
		printf("Masukan Username Akun : ");
		gets(member.usernamemember);
		printf("Masukan password Akun : ");
		gets(member.passmember);
		fwrite(&member,sizeof(member),1,f_regismember);
		fclose (f_regismember);
		printf("\nNama berhasil diregistrasi\nSilahkan login\n\n");
		system("PAUSE");system("cls");
//	loginmember();
		fwrite(&member,sizeof(member),1,f_regismember);
		fclose(f_regismember);
		main();	
	}
	
int loginmember(){//ini adalah halaman login member

	
	int i=0,n=0,b=3,y;

	if(x>0){
	//system ("cls");
	printf("\n\n====Halaman Login Member====\n");
	printf("Username : ");	fflush(stdin);gets(username);
	printf("\nPassword : "); gets(pass);
	
	FILE*f_akunmember;
	f_akunmember = fopen("regisakunmember.dat","rb");
	rewind(f_akunmember);
	while(fread(&member,sizeof(member),1,f_akunmember)==1)
	{
	if((strcmp(member.usernamemember,username)==0 && strcmp(member.passmember,pass)==0)){
		y=1;break;// login berhasil
	//	menumember();
	main();
	}
	
}
	fclose(f_akunmember);
	
	 if(y==1){
		printf("\nLOGIN BERHASIL\n");
		menumember();
	} 
		
	else {
		printf("LOGIN GAGAL\nsilahkan login ulang");
			x--;
		
		loginmember();
		
	}
	} else{
	
		printf("\nKemsempatan habis");
		printf("\n=== Kembali ke menu utama===");
		printf("\n\n");
		system("pause");system("cls");
		
		
	}
	loginmember();
}


	int menumember(){//menu utama member
	int pilih;
	system("cls");
	printf("====MENU MEMBER====\n");
	printf("silahkan pilih menu yang anda inginkan\n\n");
	printf("1. Lihat list buku");
	printf("\n2. Lihat history peminjaman");
	printf("\n3. List buku yang ingin dipinjam");
	printf("\n4. Pengembalian buku");
	printf("\n5. Logout");
	printf("\n\nPilih Nomor menu yang anda inginkan : ");
	scanf("%d",&pilih);
	getchar();
	switch(pilih){
		case 1 : system("CLS");cekbuku(); break;
		case 2 : system("CLS");historypeminjaman();break;
		case 3 : system("CLS");tanggalminjam();break;
		case 4 : system("CLS");pengembalian();break;
		case 5 : system("cls");main();
		default : system("cls");
				printf("\nMenu yang anda pilih tidak tersedia\nsilahkan mengisi ulang nomor menu \n\n");
				printf("klik enter agar dapat memilih menu\n\n");
				system("pause");
				menumember();break;
				
	}
	
	return 0;
}



int menuadmin(){
	
int pilihmenuadmin;
system("cls");
printf("====MENU ADMIN====\n\n");
printf("1. Cek Buku Yang Tersedia\n2. Tambahan Buku\n3. Update Info Buku \n4. Hapus Buku\n5.List Member\n6.Edit Info Member\n7. Hapus Member\n8. Logout\n");
	printf("Menu Yang Dipilih : "); 
	scanf("%d", &pilihmenuadmin);getchar();
	switch (pilihmenuadmin){
		case 1 : system("CLS"); cekbuku(); break;
		case 2 : system("CLS"); tambahan(); break;
		case 3 : //system("CLS"); updateinfobuku(); break;
		case 4 : system("CLS"); hapusbuku(); break;
		case 5 : system("CLS"); listmember(); break;
		case 6 : //system("CLS"); editmember();break;
		case 7 : system("CLS"); hapusmember(); break;
		case 8 : {
			system("CLS");main();
			break;
		}
		default:  printf("Menu Yang Dipilih Tidak Tersedia!!!\n SILAHKAN PILIH ULANG MENU"); menuadmin();break; 
	}
}

//menu tambah buku
int tambahan(){
	int i,n;
	listbuku = fopen("daftarbuku.dat","ab"); 
	printf("Banyak buku yang ingin dimasukan : ");
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		fflush(stdin);
		printf("\n\n%d.\tJudul buku : ",i);
		gets(buku.judul);
		printf("\tkategori buku : ");
		gets(buku.kategori);
		fflush(stdin);
		printf("\tTahun rilis buku : ");
		scanf("%d",&buku.tahunrilis);
		fflush(stdin);
		printf("\tSinopsis buku :\n");
		printf("\t");
		gets(buku.sinopsis);
		fwrite(&buku,sizeof(buku),1,listbuku);
	}
	fclose(listbuku);
	menuadmin();	
}

//menu menampilkan list buku
int cekbuku(){
	int i=0,n;
	listbuku=fopen("daftarbuku.dat","rb");
	system("cls");
		printf("====DAFTAR BUKU====");	
	while(fread(&buku,sizeof(buku),1,listbuku)==1){
		printf("\n\n%d.Judul buku : %s",i+1,buku.judul);
		printf("\n\tkategori buku : %s",buku.kategori);
		printf("\n\tTahun rilis buku : %d",buku.tahunrilis);
		printf("\n\tSinopsis buku :\n\t%s",buku.sinopsis);
		i++;
}
fclose(listbuku);
getchar();
menuadmin();
}

//cek buku member
int cekbukumember(){
	int i=0,n;
	listbuku=fopen("daftarbuku.dat","rb");
	system("cls");
		printf("====DAFTAR BUKU====");	
	while(fread(&buku,sizeof(buku),1,listbuku)==1){
		printf("\n\n%d.Judul buku : %s",i+1,buku.judul);
		printf("\n\tkategori buku : %s",buku.kategori);
		printf("\n\tTahun rilis buku : %d",buku.tahunrilis);
		printf("\n\tSinopsis buku :\n\t%s",buku.sinopsis);
		i++;	
}
fclose(listbuku);
getchar();
menumember();
}

//menu hapus buku
int hapusbuku(){
	listbuku=fopen("daftarbuku.dat","rb");
	listbuku2=fopen("daftarbuku2.dat","wb");
	printf(" Masukkan data yang ingin dihapus : ");
	gets(cari);
	getchar();
	while(fread(&buku,sizeof(buku),1,listbuku)==1){
	if(strcmp(buku.judul ,cari)!=0){
	fwrite (&buku,sizeof(buku),1,listbuku2);
}
	}
	fclose(listbuku);
	fclose(listbuku2);
	remove ("daftarbuku.dat");
	rename ("daftarbuku2.dat","daftarbuku.dat");
	menuadmin();
}

int listmember(){
	char username[99],pass[99];//login member
  	
	int i=1;
	
	
	f_regismember = fopen("regisakunmember.dat","rb");
	printf("====list member====");
	while(fread(&member,sizeof(member),1,f_regismember)==1){
		
		printf("\n\n%d.\tNama : %s",i,member.namamember);
		printf("\n\tKelas: %s",member.kelasmember);
		printf("\n\tUsia : %d ",member.usia);
		printf("\n\tInstitusi : %s",member.institusi);
		printf("\n\tUsername Akun : %s ",member.usernamemember);
		printf("\n\tpassword Akun : %s",member.passmember);
		i++;
}
	
	fclose(f_regismember);
	getchar();
	menuadmin();
	
}

int hapusmember(){
	f_regismember=fopen("regisakunmember.dat","rb");
	f_regismember2=fopen("regisakunmember2.dat","wb");
	printf(" Masukkan data member yang ingin dihapus : ");
	gets(cari);	getchar();
	while(fread(&member,sizeof(member),1,f_regismember)==1){
	if(strcmp(member.namamember ,cari)!=0){
	fwrite (&member,sizeof(member),1,f_regismember2);
}
	}
	fclose(f_regismember);
	fclose(f_regismember2);
	remove ("regisakunmember.dat");
	rename ("regisakunmember2.dat","regisakunmember.dat");
	getchar();
	menuadmin();
}

int pengembalian(){
FILE*f_pengembalian;
int hari2,bulan2,tahun2;
int hari, bulan, tahun;
int lamapinjam,denda;
f_pengembalian=fopen("tanggalminjambuku.dat","ab+");
	printf("\nHari ini adalah %i-%i-%i \n",hari,bulan,tahun);
    printf("Masukkan Tanggal Pengembalian   : ");scanf("%d-%d-%d", &hari2, &bulan2, &tahun2);
    printf("Denda/Hari (Setelah Hari ke-7) : Rp.2000-\n");
    printf("\n\nDATA PENGEMBALIAN BUKU\n");
    lamapinjam  = (tahun-tahun2)*365 + (bulan-bulan2)*30 - (hari-hari2);
    printf("Lama Pinjam \t: %d hari",lamapinjam);
    if (lamapinjam>7){
	printf("\nDenda Yang ditanggung : Rp. %d");
	}
	else{
	printf("\nDenda Anda : Rp. 0");
	}
	system("pause");
	fclose(f_pengembalian);
	system("PAUSE\n");system("cls");
	menumember();	
}

int tanggalminjam(){
FILE*f_tanggalminjam;
int hari, bulan, tahun, pil,i,n;
f_tanggalminjam=fopen("tanggalminjambuku.dat","ab");
printf("Masukkan Tanggal Hari Ini (dalam angka)\n");
		printf("\nHari  : "); scanf("%i",&hari);
		printf("Bulan : "); scanf("%i",&bulan);
		printf("Tahun : "); scanf("%i",&tahun);
		printf("\nHari ini adalah %i-%i-%i \n",hari,bulan,tahun);
		system("pause");
		fclose(f_tanggalminjam);
		system("cls");
		peminjaman();
		}

int peminjaman(){
FILE*f_tanggalminjam;
FILE*f_peminjaman;
char caribuku[100],teks[100];
int jumlahbuku,i,n,a[100];
int hari, bulan, tahun;
	f_tanggalminjam = fopen("tanggalminjambuku.dat","rb");
	f_peminjaman = fopen("Peminjaman Buku.dat", "wb+");
	printf("Masukkan Judul Buku Yang Ingin Dipinjam :");
		  scanf("%s",&caribuku);
          i=0;
          while((i<=n-1)&&(a[i]!=caribuku))
          i=i+1;
          if(a[i]==caribuku)   
			if(strcmp(caribuku,buku.judul)==1){
			printf("\nBuku yang anda cari dengan Judul Buku %s masih tersedia",caribuku);
			fwrite(&buku,sizeof(buku),1,listbuku);
			printf("\nApakah anda ingin meminjam buku? (y/n) : "); gets(teks);
			while (strcmp(teks, "Y") == 0 || strcmp(teks, "y") == 0);
			system("cls");
			
			printf("\nMember Dengan Nama : %s",member.namamember);
			printf("\nKelas              : %s ",member.kelasmember);
			printf("\nUsia               : %i ",member.usia);
			printf("\nInstitusi          : %s",member.institusi);
			printf("\n\nTelah Meminjam Buku Dengan Detail Judul Buku : %s ",buku.judul);
			printf("\nKategori Buku                                : %s ",buku.kategori);
			printf("\nTahun Rilis Buku                             : %i",buku.tahunrilis); 
			printf("\nSinopsis Buku                                : %s",buku.sinopsis);
			printf("\nPada Tanggal %i-%i-%i",hari,bulan,tahun);
			} 
			else(fread(&buku,sizeof(buku),1,listbuku)!=1);{
			printf("\nBuku yang anda cari dengan Judul Buku %s tidak tersedia",caribuku);
			printf("\nApakah anda ingin meminjam buku? (y/n) : "); gets(teks);
			while (strcmp(teks, "N") == 0 || strcmp(teks, "n") == 0);
			system("cls");
			menumember();
			}
		}
		
int historypeminjaman(){
FILE*f_tanggalminjam;
FILE*f_peminjaman;
FILE*f_historypeminjaman;
char caribuku[100];
int hari, bulan, tahun;
	f_tanggalminjam = fopen("tanggalminjambuku.dat","rb");
	f_peminjaman = fopen("Peminjaman Buku.dat", "rb");
	f_historypeminjaman = fopen("Peminjaman Buku.dat", "rb");
	printf("\n\nAnda Telah Meminjam Buku Dengan Judul Buku : %s ",caribuku);
	printf("\nPada Tanggal %i-%i-%i",hari,bulan,tahun); 
	system("cls");
	menumember();
	}
