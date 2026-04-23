#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    Void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodebaru = new Node;
        nodebaru->noMhs = nim;
    
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }

            nodebaru->next = START;
            START = nodebaru;
            return;
        }
        
        Node *previous = START;
        Node *current = START;

        while (current !=NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        
        nodebaru->next = current;
        previous->next = nodebaru;
    }
    
    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, Node *&previous, Node *&current)
    {
        previous = START;
        current = START;

        while (current !=NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!search(nim, previous, current))
           return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;
            
        delete current;
        return true;    
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData di dalam list adalah:\n";
            Node *currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
}
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambahkan data ke dalam list" << endl;
        cout << "2.Menghapus data dari dalam list" << endl;
        cout << "3.Menampilkan semua data didalam list" << endl;
        cout << "4.Mencari data dalam list" << endl;
        cout << "5.keluar" << endl;

        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        swith (ch)
        {
        case '1':
             mhs.addNode();
             break;
         
        case '2':
           if (mhs.listEmpty())
           {
            cout << "\nList Kosong\n";
            break;
           }     

           cout << "\nMasukkan nomor mahasiswa yang akan dihapus : ";
           cin >> nim;

           if (mhs.delNode(nim) == false)
           cout << "\nData tidak ditemukan" << endl;
           else
               cout << "\nData dengan nomor mahasiswa " << nim << " berhasil di hapus"\n";
            break;
            
        case '3':
            mhs.traverse();
            break;

        case '4':
        {
            if  (mhs.listEmpty())
            {
                cout << "\list kosong\n";
                break;    
            }

            Node *previous, *current;
            cout << "\nMasukkan nomor mahasiswa yang akan di cari : ";
            cin >> nim;

            if (mhs.search(nim, previous current) == false)
                cout << "\nData tidak ditemukan\n";
            else
            {
                cout << "\nData ditemukan\n";
                cout << "\nNomor mahasiswa : " << current->noMhs << endl;
            }
            break;
        }

        case '5' :
            break;

        default: 
            cout << "\nPilihan salah\n";
        }    

    } while (ch != '5');

    return 0;
}

