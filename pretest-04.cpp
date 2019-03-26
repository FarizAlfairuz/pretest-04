/*
Nama        : Falah Rizqi Abudllah Fairuz
NPM         : 140810180069
Deskripsi   : Double linked list
Kelas       : A
Tanggal     : 26 Maret 2019
*/

#include <iostream>
using namespace std;

struct ElemList
{
    char npm[14];
    char nama[40];
    float ipk;
    ElemList* next;
};

typedef ElemList* pointer;
typedef pointer List;

void createList (List& first)
{
    first = NULL;
}

void createElement (pointer& pBaru)
{
    pBaru = new ElemList;
    cout << "Nama       : "; cin >> pBaru->nama;
    cout << "NPM        : "; cin >> pBaru->npm;
    cout << "IPK        : "; cin >> pBaru->ipk;
    pBaru->next = NULL;
}

void insertSortNPM (List& first, pointer pBaru)
{
    pointer last;

    cout << "Insert data : " << endl;

    if (first == NULL)
    {
        first = pBaru;
    }

    else
    {
        last = first;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = pBaru;
    }
    
}

void traversal (List first)
{
    pointer pBantu;
    if (first == NULL)
    {
        cout << "List kosong" << endl;
    }

    else
    {
        pBantu = first;
        int i = 1;
        do
        {
            cout << "                   Data Mahasiswa                 " << endl;
            cout << "==================================================" << endl;
            cout << "No     NPM     Nama                    IPK        " << endl;

            cout << i << "  " << pBantu->npm << "\t\t" << pBantu->nama << "\t\t\t" << pBantu->ipk << endl;
            pBantu = pBantu->next;
            ++i;
        } while (pBantu != NULL);
        cout << endl;
    }
    
}

main ()
{
    pointer p;
    List l;
    int menu;
    createList (l);

    do
    {
        cout << "1. Tambah data" << endl;
        cout << "2. Keluaran" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih : "; cin >> menu;

        if (menu == 1)
        {
            createElement (p);
            insertSortNPM (l,p);
        }
        else if (menu == 2)
        {
            traversal (l);
        }
        else
        {
            cout << "Exit" << endl;
        }
        
    } while (menu == 1 || menu == 2);
    
}