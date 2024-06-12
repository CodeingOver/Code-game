#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct sinhvien
{
    string masosinhvien;
    string hoten;
    float diemkithuatlaptrinhl;
    float diemtoanroirac;
    float diemctdl;
    float diemtb;
};
typedef struct sinhvien sv;
void nhap(sv &a);
void xuat(sv a);
void xeploai(sv a);
float diemTB(sv &a);
void xapxepthemdiemTB(sv a[],int n);
void xuatnhieu(sv a[],int n);
void xapxepthemdiemTB1(sv a[],int n);
void sapxeptheoten(sv a[],int n);
void nhapdulieuvaofile(sv a[],int n);
void laydulieutufilera(sv a[],int &n);
void xoa(sv a[],int &n,int vt);
void xoatrungnhau(sv a[],int &n);
string xoakhoangtrang(string &a);
int main()
{
    //setting
    sv a[100]; 
    int n=0;
    laydulieutufilera(a,n);
    //play
    bool kt_menu=true;
    while(kt_menu==true)
    {
        system("cls");
        cout<<"1=>Nhap danh sach sinh vien"<<endl;
        cout<<"2=>Xuat danh sach sinh vien"<<endl;
        cout<<"3=>Xap xep danh sach sinh vien theo diem TB (Giam dan)"<<endl;
        cout<<"4=>Xap xep danh sach sinh vien theo diem TB (Tang dan)"<<endl;
        cout<<"5=>Xap xep danh sach sinh vien theo ten"<<endl;
        cout<<"77=>Xoa het du lieu trong file"<<endl;
        cout<<"88=>Luu du lieu vao trong file"<<endl;
        cout<<"9999=>Thoat ma khong luu"<<endl;
        cout<<"0=>Thoat"<<endl;
        int luachon;cout<<"Nhap lua chon: ";cin>>luachon;
        switch(luachon)
        {
            case 1:
            {
                int x;cout<<"Nhap so luong sv can nhap: ";cin>>x;
                system("cls");
                for(int i=0;i<x;i++)
                {
                    cin.ignore();
                    sv cd;
                    cout<<"--------Nhap sinh vien thu ["<<i+1<<"]"<<"--------------"<<endl;
                    nhap(cd);
                    a[n++]=cd;
                }
                break;
            }
            case 2:
            {
                system("cls");
                xuatnhieu(a,n);
                system("pause");
                break;
            }
            case 3:
            {
                xapxepthemdiemTB(a,n);
                xuatnhieu(a,n);
                system("pause");
                break;
            }
            case 4:
            {
                xapxepthemdiemTB1(a,n);
                xuatnhieu(a,n);
                system("pause");
                break;
            }
            case 5:
            {
                sapxeptheoten(a,n);
                xuatnhieu(a,n);
                system("pause");
                break;
            }
            case 6:
            {
                int vt;
                system("cls");
                xuatnhieu(a,n);
                cout<<"========================================"<<endl;
                cout<<"Nhap so cua sinh vien can xoa: ";cin>>vt;
                xoa(a,n,vt-1);
                nhapdulieuvaofile(a,n);
                system("pause");
                break;
            }
            case 77:
            {
                fstream fillfile;
                fillfile.open("danhsachsinhvien.txt",ios_base::out);
                fillfile<<"";
                fillfile.close();
                n=0;
                cout<<"Ban da xoa het du lieu trong file thanh cong"<<endl;
                system("pause");
                break;
            }
            case 88:
            {
                if(n>0)
                {
                    xoatrungnhau(a,n);
                    nhapdulieuvaofile(a,n);
                    cout<<"Ban da luu du lieu vao file thanh cong"<<endl;
                    n=0;
                    laydulieutufilera(a,n);
                }
                else
                {
                    cout<<"Ban chua nhap gi het"<<endl;
                }
                system("pause");
                break;
            }
            case 9999:
            {
                cout<<endl;system("pause");
                return 0;
            }
            case 0:
            {
                kt_menu=false;
                break;
            }
        }
    }
    if(n>0)
    {
        xoatrungnhau(a,n);
        nhapdulieuvaofile(a,n);
        cout<<"Ban da luu du lieu vao file thanh cong"<<endl;
    }
    cout<<endl;system("pause");
    return 0;
}
void nhapdulieuvaofile(sv a[],int n)
{
    fstream fo;
    fo.open("danhsachsinhvien.txt",ios_base::out);
    for(int i=0;i<n;i++)
    {
        fo<<",";
        fo<<a[i].hoten<<",";
        fo<<a[i].masosinhvien<<",";
        fo<<a[i].diemkithuatlaptrinhl<<",";
        fo<<a[i].diemtoanroirac<<",";
        fo<<a[i].diemctdl<<",";
        fo<<a[i].diemtb;
    }
    fo.close();
}
void laydulieutufilera(sv a[],int &n)
{
    fstream fi;
    fi.open("danhsachsinhvien.txt",ios_base::in);
    if(fi.fail()==true)
    {
        cout<<"Khong mo duoc file"<<endl;
        system("pause");
        return;
    }
    fi.ignore();
    while(fi.eof()==false)
    {
        getline(fi,a[n].hoten,',');
        getline(fi,a[n].masosinhvien,',');
        fi>>a[n].diemkithuatlaptrinhl;
        fi.ignore();
        fi>>a[n].diemtoanroirac;
        fi.ignore();
        fi>>a[n].diemctdl;
        fi.ignore();
        fi>>a[n].diemtb;
        fi.ignore();
        n++;
        // system("pause");
    }
    fi.close();
}
void nhap(sv &a)
{
    cout<<"Nhap ho ten sinh vien: ";getline(cin,a.hoten);
    cout<<"Nhap ma so sinh vien: ";getline(cin,a.masosinhvien);
    cout<<"Nhap diem ki thuat lap trinh: ";cin>>a.diemkithuatlaptrinhl;
    cout<<"Nhap diem toan roi rac: ";cin>>a.diemtoanroirac;
    cout<<"Nhap diem ctdl: ";cin>>a.diemctdl;
    diemTB(a);
    xoakhoangtrang(a.hoten);
    if(a.diemkithuatlaptrinhl<0||a.diemkithuatlaptrinhl>10||a.diemctdl<0||a.diemctdl>10||a.diemtoanroirac<0||a.diemtoanroirac>10)
    {
        rewind(stdin);
        system("cls");
        cout<<"Khong hop li vui long nhap lai"<<endl;
        nhap(a);
    }
}
void xoa(sv a[],int &n,int vt)
{
    for(int i=vt;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
}
void xoatrungnhau(sv a[],int &n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].masosinhvien==a[j].masosinhvien&&a[i].hoten==a[j].hoten&&a[i].diemtoanroirac==a[j].diemtoanroirac&&a[i].diemkithuatlaptrinhl==a[j].diemkithuatlaptrinhl&&a[i].diemctdl==a[j].diemctdl&&a[i].diemtb==a[j].diemtb)
            {
                xoa(a,n,j);
                cout<<"Du lieu trung da bi xoa"<<endl;
                j--;
                cout<<endl;system("pause");
            }
        }
    }
}
void xuat(sv a)
{
    cout<<"Ho ten: "<<a.hoten<<endl;
    cout<<"MSSV: "<<a.masosinhvien<<endl;
    cout<<"Diem ki thuat lap trinh: "<<a.diemkithuatlaptrinhl<<endl;
    cout<<"Diem toan roi rac: "<<a.diemtoanroirac<<endl;
    cout<<"Diem ctdl: "<<a.diemctdl<<endl;
}
void xuatnhieu(sv a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"---------Sinh vien thu ["<<i+1<<"]-------------"<<endl;
        xuat(a[i]);
        xeploai(a[i]);
    }
}
float diemTB(sv &a)
{
    return a.diemtb=(a.diemtoanroirac+a.diemctdl+a.diemkithuatlaptrinhl)/3;
}
void xeploai(sv a)
{
    if(a.diemtb>9.8)
    {
        cout<<"Diem TB: "<<a.diemtb<<endl;
        cout<<"Hoc luc: Xuat sac"<<endl;
    }
    else if(a.diemtb>=8)
    {
        cout<<"Diem TB: "<<a.diemtb<<endl;
        cout<<"Hoc luc: Gioi"<<endl;
    }
    else if(a.diemtb>=6.5)
    {
        cout<<"Diem TB: "<<a.diemtb<<endl;
        cout<<"Hoc luc: Kha"<<endl;
    }
    else if(a.diemtb>=4)
    {
        cout<<"Diem TB: "<<a.diemtb<<endl;
        cout<<"Hoc luc: Trung binh"<<endl;
    }
    else
    {
        cout<<"Diem TB: "<<a.diemtb<<endl;
        cout<<"Hoc luc: Yeu"<<endl;
    }
}
void xapxepthemdiemTB(sv a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j].diemtb>a[i].diemtb)
            {
                swap(a[i],a[j]);
            }
        }
    }   
}
void xapxepthemdiemTB1(sv a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j].diemtb<a[i].diemtb)
            {
                swap(a[i],a[j]);
            }
        }
    }   
}
void sapxeptheoten(sv a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].hoten[0]>a[j].hoten[0])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
string xoakhoangtrang(string &a)
{
    while(a[0]==' ')
    {
        a.erase(0,1);
    }
    for(int i=0;i<a.length()-1;i++)
    {
        while(a[i]==' '&&a[i+1]==' ')
        {
            a.erase(i,1);
        }
    }
    return a;
}