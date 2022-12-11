#pragma once
#include "ManageProduct.h"

using namespace std;

ManageProduct::ManageProduct() 
{
    this->p = nullptr;
    this->length = 0;
}
ManageProduct::~ManageProduct() 
{
    delete[] this->p;
}
ManageProduct::ManageProduct(Product* p, int length) 
{
    this->length = length;
    this->p = p;
}
void ManageProduct::setLength(int length)
{
    this->length = length;
}
int ManageProduct::getLength() 
{
    return this->length;
}
void ManageProduct::resetSales(string id) 
{
    for (int i = 0; i < this->length; i++) 
    {
        if ((*(this->p + i)).getId() == id) 
        {
            (*(this->p + i)).setSales(0);
        }
    }
}
Product &ManageProduct::operator[](const int i)
{
    static Product a;
    if (i >= 0 && i < this->length)
        return *(this->p + i);
    else
        return a;
}
/*void ManageProduct::showProduct(string id)
{
    for (int i = 0; i < this->length; i++) 
    {
        if ((*(this->p + i)).getId() == id) 
        {
            
            cout << endl;
            cout << "          ----------------------------------------------" << endl;
            cout << "                       INFORMATION OF PRODUCT           " << endl;
            cout << "          ----------------------------------------------" << endl;
            cout << "                   Id: " << (*(this->p + i)).getId() << endl;
            cout << "                   Name: " << (*(this->p + i)).getName() << endl;
            cout << "                   Price: " << (*(this->p + i)).getPrice() << endl;
            cout << "                   Sales: " << (*(this->p + i)).getSales() << endl;
        }
    }
}*/
void ManageProduct::add() 
{
    cout << "\n\t\t\tEnter the product: " << endl;
    Product x;
    cin >> x;
    Product* a;
    string l[20];
    for (int i = 0; i < this->length; i++)
    {
        while (x.getId() == (*(this->p + i)).getId())
        {
            Library::printError("\t\tId has been defined. Try again! ");
            cin >> x;
        }
    }
    a = new Product[this->length + 1];
    for (int i = 0; i < this->length; i++) 
    {
        *(a + i) = *(this->p + i);
    }
    *(a + this->length) = x;
    length++;
    delete[] this->p;
    this->p = a;
}
Product ManageProduct::getProduct(string id) 
{
    Product a;
    for (int i = 0; i < this->length; i++) 
    {
        if ((*(this->p + i)).getId() == id) 
        {
            return *(this->p + i);
        }
    }
    return a;
}
void ManageProduct::Remove(string id)
{
    int index = 0;
    string s;
    int t;
    for (int i = 0; i < this->length; i++) 
    {
        if ((*(this->p + i)).getId() == id) 
        {
            index = i;
            s = (*(this->p + i)).getName();
            t = (*(this->p + i)).getSales();
            break;
        }
    }
    for (int i = index + 1; i < this->length - 1; i++) 
    {
        *(this->p + i - 1) = *(this->p + i);
    }
    this->length--;
    fstream file("Database\\TurnoverProduct.txt", ios::out | ios::app);
    if (!file.is_open()) {
        cout << "\n\t\tCould not open the file: TurnoverProduct.txt" << endl;
        return;
    }
    file << s << endl;
    file << to_string(t) << endl;
    file.close();
}

string ManageProduct::getId() 
{
    system("cls");
    int n = this->length;
    show();
    int c = 0;
    cout << "\t            " << n + 1 << ". Back to Menu.\n";
    cout << "\t         ----------------------------" << endl << endl;
    cout << "\n\t\tEnter your selection: ";
    cin >> c;
    if (cin.fail())
    {
        c = Library::fail("\t\tEnter your selection");

    }
    while ((c <= 0 || c > n + 1)) 
    {
        Library::printError("Please select from the list");
        cin >> c;
    }
    if (c == n + 1 ) return "-1";
    return p[c-1].getId();
}
void ManageProduct::WriteFile(ofstream& filename)
{
    if (!filename.is_open())
    {
        cout << "\n Could not open the file!" << endl;
        return;
    }
    for (int i = 0; i < this->length ; i++)
    {
        filename << this->p[i].getId() << endl;
        filename << this->p[i].getName() << endl;
        filename << to_string(this->p[i].getPrice()) << endl;
        filename << to_string(this->p[i].getSales()) << endl;
    }
    
}
void ManageProduct::readData(string fileName)
{
    vector<string> lines;
    string line;
    ifstream input_file(fileName);
    if (!input_file.is_open())
    {
        cout << ("Could not open the file - '" + fileName + "'") << endl;
        return;
    }
    while (getline(input_file, line))
    {
        lines.push_back(line);
    }
    int k = lines.size();
    Product* a = new Product[k];
    int i = 0;
    for (int j = 0; j < k; j += 4)
    {
        a[i].setId(lines[j]);
        a[i].setName(lines[j + 1]);
        a[i].setPrice(stoi(lines[j + 2]));
        a[i].setSales(stoi(lines[j + 3]));
        i++;
    }
    input_file.close();
    delete[] p;
    this->length = i;
    this->p = a;
}
void ManageProduct::search()
{
    string name;
    cout << "\n\t\t\Enter the name that you want to search: ";
    char a[99];
    cin >> a;
    int k = -1;
    for (int i = 0; i < this->length; i++)
    {
        char Name[99];
        strcpy_s(Name, (p + i)->getName().c_str());
        Library::Toupper(a);
        Library::Toupper(Name);
        if (strstr(Name,a))
        {
            (p + i)->Show((p+i)->getSales());
            k = 0;
        }
    }
    if (k == -1)
        cout << " No found this product!" << endl;
    int e;
    cout << "\n\t\tEnter 1 to Back to StaffMenu." << endl;
    cin >> e;
    if (e == 1)
    {
        system("cls");
        StaffMenu::Display();
    }
    else return;
}
void ManageProduct::update(string id)
{
    system("cls");
    for (int i = 0; i < this->length; i++)
    {
        if (id == (*(p + i)).getId())
        {
            cout << "\n\t\t   ------------------------------------" << endl;
            cout << "\t\t\t\t" <<(*(p + i)).getId() << endl;
            cout << "\t\t   ------------------------------------"   << endl;
            cout << "\n\t\t\t    1. Update Id." << endl;
            cout << "\t\t\t    2. Update Name." << endl;
            cout << "\t\t\t    3. Update Price." << endl;
            cout << "\t\t\t    4. Update Sales." << endl;
            cout << "\t\t\t    5. Update Product." << endl;
            cout << "\t\t\t    6. Back to Menu." << endl;
            cout << "\n\t\t   ------------------------------------" << endl;

            int k;
            cout << "\n\t\t   Enter your choice: ";
            cin >> k;
            switch (k)
            {
                case 1:
                {
                    cout << "\t\t Id: ";
                    string r;
                    cin >> r;
                    for (int i = 0; i < this->length; i++)
                    {
                        if (r == (*(this->p + i)).getId())
                        {
                            Library::printError("\t\tId has been defined. Try again! ");
                            cout << "\t\tId: ";
                            cin >> r;
                        }
                    }
                    p->setId(r);
                    break;
                }
                case 2:
                {
                    cout << "\t\t Name: ";
                    string r;
                    //fflush(stdin);
                    cin.ignore();
                    getline(cin, r);
                    p->setName(r);
                    break;
                }
                case 3:
                {
                    cout << "\t\t Price: ";
                    int r;
                    cin >> r;
                    if (cin.fail()) {
                        Library::fail("\t\tPrice");
                    }
                    p->setPrice(r);
                    break;
                }
                case 4:
                {
                    cout << "\t\t Sales: ";
                    int r;
                    cin >> r;
                    if (cin.fail()) {
                        Library::fail("\t\tSale");
                    }
                    p->setSales(r);
                    break;
                }
                case 5:
                {
                    add();
                    break;
                }
                case 6:
                {
                    system("cls");
                    StaffMenu::Display();
                    break;
                }
                default:
                {
                    Library::printError("\t\tPlease select from 1 to 6");
                    break;
                }
            }
            break;
        }
    }
}
void ManageProduct::showProduct(string id)
{
    for (int i = 0; i < this->length; i++)
    {
        if ((*(this->p + i)).getId() == id)
        {

            cout << endl;
            cout << "          ----------------------------------------------" << endl;
            cout << "                       INFORMATION OF PRODUCT           " << endl;
            cout << "          ----------------------------------------------" << endl;
            cout << "                   Id: " << (*(this->p + i)).getId() << endl;
            cout << "                   Name: " << (*(this->p + i)).getName() << endl;
            cout << "                   Price: " << (*(this->p + i)).getPrice() << endl;
            cout << "                   Sales: " << (*(this->p + i)).getSales() << endl;
        }
    }
}
void ManageProduct::updateSale(string filename, string id, int x) {
    for (int i = 0; i < this->length; i++) {
        if (p[i].getId() == id) {
            int k = p[i].getSales() + x;
            p[i].setSales(k);
            ofstream file;
            file.open(filename, ios_base::out);
            WriteFile(file);
        }
    }
}
void ManageProduct::showRevenues() {
    for (int i = 0; i < this->length; i++) {
        cout << "\t\t" << left << setw(30) << (*(p + i)).getName() << ": " << setw(15);
        int r = (*(p + i)).getSales() * (*(p + i)).getPrice();
        string m = Library::printRevenues(r, ".");
        Library::printLineColor(m, 2);
        cout << " vnd." << endl;
    }
    cout << endl;
}
void ManageProduct::show()
{
    system("cls");
    int n = this->length;
    int c = 0;
    string l[20];
    cout << "\t         -----------------------------" << endl;
    cout << "\t                      LIST            " << endl;
    cout << "\t         -----------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " \t            " << i + 1 << ". " << (*(p + i)).getName() << endl;
    }
}