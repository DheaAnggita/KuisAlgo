#include <iostream>
#include <time.h>

using namespace std;

struct tiket {
	string nama, no_kursi;
	int kode;
	};
struct kursi {
	string nomor;
	bool status = true;
	};
	
void tampil(int i, int j);
void pesan();
void masuk();
int menu();
struct kursi kursi1[10][10];
struct tiket tiket1[100];
int index=0;
int main()
{
	
	string huruf[10] = { "A","B","C","D","E","F","G","H","I","J"};
	string angka[10] = { "1","2","3","4","5","6","7","8","9","10"};
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			kursi1[i][j].nomor = huruf[i] + angka[j];
		}
	}
	do{
	switch(menu()){
		case 1 :
		pesan();
		break;
		case 2 :
		masuk();
		break;
		case 3 :
		cout << "Program Selesai" << endl;
		return 0;
		break;
		default : cout << " Menu Tidak Tersedia " << endl;
	}
	}while(true);
	
	
	
}

void tampil(int i, int j){
	cout << kursi1[i][j].nomor << " ";
	if(j < 9){
		tampil(i, ++j);
	}
	else if(i < 9){
		cout << endl;
		tampil(++i, 0);
	}
	
	
}

int menu(){
	int pil;
	cout << "===========================" << endl;
	cout << "	PROGRAM BIOSKOP	" << endl;
	cout << "===========================" << endl;
	cout << "1. Pesan tiket " << endl;
	cout << "2. Masuk ke Bioskop " << endl;
	cout << "3. Keluar " << endl;
	cout << "pilih : "; cin >> pil;
	return pil;
}
void pesan(){
	string input;
	bool found = false;
	srand((unsigned)time(NULL));
	cout << "===============================" << endl;
	cout << "	Kursi Bioskop	" << endl;
	cout << "===============================" << endl;
	cout << "	    Layar	" << endl;
	tampil(0,0);
	cout << endl;
	cin.ignore();
	cout << "===============================" << endl;
	cout << "Nama		: "; getline(cin, tiket1[index].nama);
	do{
		cout << "Pilih Kursi	: "; cin >> input;
		for (int i=0; i<10; i++){
			for (int j=0; j<10; j++){
				if( input == kursi1[i][j].nomor and kursi1[i][j].status == true){
					kursi1[i][j].nomor = "XX";
					kursi1[i][j].status = false;
					found = true;
					break;
				}
			}
		}
		if(found){
			tiket1[index].no_kursi = input;
			tiket1[index].kode = (rand()% 8999) + 1000;
			
		}
		else{
			cout << "Kursi Tidak Ditemukan atau Kursi Sudah Ditempati!" << endl;
		}
	}while(!found);
	
	system("cls");
	cout << "============Struk=============" << endl;
	cout << "Nama		: " << tiket1[index].nama << endl;
	cout << "Nomor Kursi	: " << tiket1[index].no_kursi << endl;
	cout << "Kode Booking	: " << tiket1[index].kode << endl;
	cout << "==============================" << endl;
	cout << "   Mohon ingat Kode Booking!" << endl;
	cout << "==============================" << endl;
	index++;
	system("pause");
	system("cls");
	
}

void masuk(){
	int kode;
	bool found;
	int i;
	do{
	cout << "Masukkan kode booking : "; cin >> kode;
	found = false;
	i = 0;
	while((i < 100) & (!found))
	{
		if(tiket1[i].kode == kode)
			found = true;
		else
			i = i + 1;
	}
	if(found){
		cout << "===============================================" << endl;
		cout << " Nama		: " << tiket1[i].nama <<endl;
		cout << " Nomor Kursi	: " << tiket1[i].no_kursi << endl;
		cout << "===============================================" << endl;
	}
	else
		cout << "Kode booking tidak terdaftar!" << endl;
	}while(!found);
	
		cout << " ============================================" << endl;
		cout << "| Nomor Kursi anda adalah " << tiket1[i].no_kursi << ". Silakan Masuk! |" << endl;
		cout << " ============================================" << endl;
		system("pause");
		system("cls");
	
	 
	
}
