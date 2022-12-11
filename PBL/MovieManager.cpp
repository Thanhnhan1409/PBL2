#include "MovieManager.h"
using namespace std;
MovieManager::MovieManager() {
    this->movie = nullptr;
    this->length = 0;
}
MovieManager::~MovieManager() {
    delete[] this->movie;
}

int MovieManager::getLength() {
    return this->length;
}
void MovieManager::setLength(int length)
{
    this->length = length;
}
bool MovieManager::isDuplicateId(Movie x) {
    bool t = false;
    for (int i = 0; i < this->length; i++) {
        if (x.getId() == (*(this->movie + i)).getId()) {
            t = true;
        }
    }
    return t;
}
void MovieManager::addMovie(Movie x) {
    while (isDuplicateId(x))
    {
        cout << " \nNew movie's id is duplicated. Please enter again: ";
        string i;
        cin >> i;
        x.setId(i);
    }
    if (this->length == 0) {
        if (this->movie != nullptr) {
            delete[] this->movie;
        }
        this->movie = new Movie[1];
        *(this->movie) = x;
        ++this->length;
        return;
    }
    Movie* a;
    a = new Movie[this->length + 1];
    for (int i = 0; i < length; i++) {
        *(a + i) = *(this->movie + i);
    }
    *(a + length) = x;
    delete[] this->movie;
    this->movie = a;
    this->length++;
    ofstream file("Database\\Movie\\" + x.getId() + ".txt");
    file << x.getId() << endl;
    file << x.getName() << endl;
    file << x.getType() << endl;
    file << to_string(x.getDuration()) << endl;
    file << to_string(x.getYear()) << endl;
    file << x.getTime() << endl;
    file << x.getCountry() << endl;
    file << x.getContent() << endl;
    file << x.getActor() << endl;
    file << x.getCine() << endl;
    file << x.getShowtime() << endl;
    file << x.getSales() << endl;
    file << x.getPrice() << endl;
    file.close();
    //add them vao file 
    fstream inp_file("Database\\Movie\\movie.txt", ios::out | ios::app);
    if (!inp_file.is_open()) {
        cout << "\nCould not open the file: movie.txt" << endl;
        return;
    }
    inp_file << endl;
    inp_file << x.getId();
    inp_file.close();
    //Library::printLineColor("Add movie to database successfully!");
    cout << "\nAdd movie to database successfully! " << endl;
}
void MovieManager::show()
{
    int n = this->length;
    int c = 0;
    string l[20];
    cout << "\t     --------------------------------\n";
    Library::printLineColor("\t                LIST FILM\n", 4);
    cout << "\t     --------------------------------\n\n";
    for (int i = 0; i < n; i++) {
        cout << "\t         " << i + 1 << ". " << (*(movie + i)).getName() << endl;
    }
}
Movie MovieManager::getMovie(string id) {
    for (int i = 0; i < this->length; i++) {
        if ((*(movie + i)).getId() == id) {
            return *(movie + i);
        };
    };
    cout << "Error";
    Movie obj;
    return obj;
}
void MovieManager::update(string id) {
    cout << "\n\t\t   ------------------------------------" << endl;
    cout << "\t\t\t\tUpdate Movie\n";
    cout << "\n\t\t   ------------------------------------" << endl;
    int k = 0;
    for (int i = 0; i < this->length; i++)
    {
        if (id == (*(movie + i)).getId())
        {
            k = i;
            cout << "\t\t    1. Update Cinema and Showtime" << endl;
            cout << "\t\t    2. Update Price." << endl;
            cout << "\t\t    3. Back to Menu." << endl;
            int k;
            cout << "\n\t\t    Enter your choice: ";
            cin >> k;
            if (cin.fail())
            {
                k= Library::fail("\t\t    Enter your selection");

            }
            switch (k)
            {
            case 1:
            {
                int a[6][4];
                char cine;
                string showtime;
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 4; j++) {
                        a[i][j] = 1;
                    }
                }
                for (int i = 0; i < this->length; i++) {
                    Movie p = *(movie + i);
                    string c = p.getCine();
                    int t2 = -1;
                    if (c == "A") {
                        t2 = 0;
                    }
                    else  if (c == "B") {
                        t2 = 1;
                    }
                    else if (c == "C") {
                        t2 = 2;
                    }
                    else if (c == "D") {
                        t2 = 3;
                    }
                    stringstream s = (stringstream)p.getShowtime();
                    while (s.good()) {
                        string q;
                        getline(s, q, ',');
                        int t = -1;
                        if (q == "8:15") {
                            t = 0;
                        }
                        if (q == "11:10") {
                            t = 1;
                        }
                        if (q == "14:15") {
                            t = 2;
                        }
                        if (q == "17:05") {
                            t = 3;
                        }
                        if (q == "19:25") {
                            t = 4;
                        }
                        if (q == "22:20") {
                            t = 5;
                        }
                        if (t != -1 && t2 != -1) {
                            a[t][t2] = 0;
                        }

                    }
                }
                Library::printLineColor("\t\tCinema's Schedule", 3);
                cout << "\n\n";
                cout << "   ";
                for (int i = 0; i < 7; i++) {
                    cout << "                ";
                    for (int j = 0; j < 5; j++) {
                        if (i == 0 && j == 0) continue;
                        if (i == 0 && j != 0) {
                            printf("%3c", j + 64);
                        }
                        else if (j == 0 && i != 0) {
                            printf("%3d", i);
                            cout << " ";
                        }
                        else {
                            if (a[i - 1][j - 1] == 1) {
                                Library::printLineColor(" 1 ", 2);
                            }
                            else {
                                Library::printLineColor(" 0 ", 4);
                            }
                        }
                    }
                    cout << endl;
                }
                bool again = true;
                while (again) {
                    cout << "\t\tCinema: ";
                    cin.clear();
                    cin >> cine;
                    cine = toupper(cine);
                    cout << "\t\tShowtime: " << endl;
                    cout << "\t\tSet 1: 8:15" << endl;
                    cout << "\t\tSet 2: 11:10" << endl;
                    cout << "\t\tSet 3: 14:15" << endl;
                    cout << "\t\tSet 4: 17:05" << endl;
                    cout << "\t\tSet 5: 19:25" << endl;
                    cout << "\t\tSet 6: 22:20" << endl;
                    cout << "\t\tEnter amount showtime: ";
                    int sl;
                    int q;
                    cin >> sl;
                    while ((sl <= 0 || sl > 6) || cin.fail()) {
                        if (cin.fail()) {
                            Library::fail("\t\tAmount of showtime");
                        }
                        cin.ignore(32767, '\n');
                        cout << "\t\tPlease enter again: ";
                        cin >> sl;
                    }

                    bool l = false;
                    for (int i = 0; i < sl; i++) {

                        cout << "\t\tEnter showtime (Number): ";
                        cin >> q;
                        if (cin.fail())
                        {
                            Library::fail("\t\tEnter showtime(Number) ");
                        }

                        while ((q <= 0 || q > 6)) {
                            cout << "\t\tPlease select from the list: ";
                            cin >> q;
                        }
                        if (q == 1) {
                            showtime += "8:15";
                        }
                        else if (q == 2) {
                            showtime += "11:10";
                        }
                        else if (q == 3) {
                            showtime += "14:15";
                        }
                        else if (q == 4) {
                            showtime += "17:05";
                        }
                        else if (q == 5) {
                            showtime += "19:25";
                        }
                        else if (q == 6) {
                            showtime += "22:20";
                        }
                        else {
                            cout << "\t\tPlease select from the list! " << endl;
                        }
                        showtime += ",";
                        int e;
                        if (cine == 'A') {
                            e = 0;
                        }
                        else  if (cine == 'B') {
                            e = 1;
                        }
                        else if (cine == 'C') {
                            e = 2;
                        }
                        else if (cine == 'D') {
                            e = 3;
                        }
                        if (a[q - 1][e] == 0) {
                            Library::printError("\t\tCinema " + string(1, cine) + " in set " + to_string(q) + " already taken! Please select again!");
                            l = true;
                            break;
                        }
                    }
                    if (!l) again = false;

                }
            (movie+i)->setCine(string(1, cine));
            Library::printSuccess("\t\t    Done!");
            break;
            }
            case 2:
            {
                cout << "\t\t    Enter price: ";
                int p;
                cin >> p;
                (movie + i)->setPrice(p);
                Library::printSuccess("\t\t    Done!");
                break;
            }
            case 3:
            {
                StaffMenu::Display();
                break;
            }
            default:
                break;
            }
        }
    }
    Movie x = *(movie + k);
    ofstream file("Database\\Movie\\" + id + ".txt");
    file << x.getId() << endl;
    file << x.getName() << endl;
    file << x.getType() << endl;
    file << to_string(x.getDuration()) << endl;
    file << to_string(x.getYear()) << endl;
    file << x.getTime() << endl;
    file << x.getCountry() << endl;
    file << x.getContent() << endl;
    file << x.getActor() << endl;
    file << x.getCine() << endl;
    file << x.getShowtime() << endl;
    file << x.getSales() << endl;
    file << x.getPrice() << endl;
    file.close();
    //cout << "\nAdd movie to database successfully! " << endl;
}
void MovieManager::Remove(string id) {
    string z[6] = { "8:15","11:10","14:15","17:05","19:25","22:20" };
    Movie p = getMovie(id);
    string c = p.getCine();
    stringstream s = (stringstream)p.getShowtime();
    while (s.good()) {
        string q;
        getline(s, q, ',');
        int t = -1;
        for (int i = 0; i < 6; i++) {
            if (z[i] == q) {
                t = i + 1;
            }
        }
        if (t != -1) {
            Cinema::resetCine(t, p.getCine());
        }
    }
    string link = "Database\\Movie\\" + id + ".txt";
    const char* path = &link[0];
    int ret = remove(path);
    bool is_ok = (ret == 0) ? true : false;
    if (!is_ok) {
        cout << "\nRemove movie failed" << endl;
    }
    string str = "Database\\Movie\\movie.txt";
    ifstream file1(str);
    if (!file1.is_open()) {
        cout << "\nCould not open the file movie.txt" << endl;
    }
    string index;
    while (getline(file1, index)) {
        if (index == id) {
            break;
        }
        else index = "-1";
    }
    file1.close();
    if (index == "-1") {
        cout << "\nCould not open the movie ( id=" + id + ")" << endl;
    }
    else {
        string path = "Database\\Movie\\movie.txt";
        string eraseLine = id;
        string line;
        ifstream fin;

        fin.open(path.c_str());
        ofstream temp;
        temp.open("Database\\Movie\\temp.txt");

        vector<string>lines;
        while (getline(fin, line)) {
            if (!line.empty() && line != eraseLine) {
                lines.push_back(line);
            }
        }
        for (int i = 0; i < lines.size() - 1; i++) {
            if (lines[i] != eraseLine && !lines[i].empty()) {
                temp << lines[i] << endl;
            }
        }
        temp << lines[lines.size() - 1];

        temp.close();
        fin.close();
        const char* p = path.c_str();
        remove(p);
        rename("Database\\Movie\\temp.txt", p);
    }
}
void MovieManager::readData(string filename) {
    ifstream inp_file(filename);
    if (!inp_file.is_open()) {
        cout << "\nCould not open the file movie.txt" << endl;
        return;
    }
    string id;
    vector< string> ls;
    while (getline(inp_file, id)) {
        ls.push_back(id);
    }
    inp_file.close();
    this->movie = new Movie[ls.size()];
    this->length = ls.size();
    for (size_t i = 0; i < ls.size(); i++) {
        string link = "Database\\Movie\\" + ls[i] + ".txt";
        string filename(link);
        vector< string> lines;
        string line;
        //Mở file bằng ifstream
        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cout << "\nCould not open the file - '" + filename + "'" << endl;
            return;
        }

        //Đọc từng dòng trong
        while (getline(input_file, line)) {
            lines.push_back(line);//Lưu từng dòng như một phần tử vào vector lines.
        }

        Movie obj(lines[0], lines[1], lines[2], lines[7], lines[5], stoi(lines[4]), stoi(lines[3]), lines[8], lines[6], lines[9], lines[10], stoi(lines[11]), stoi(lines[12]));
        //Error
        *(this->movie + i) = obj;
        input_file.close();
    }
    return;
}
string MovieManager::getId()
{
    int n = this->length;
    show();
    int c = 0;
	cout << "\t         " << n + 1 << ". Back to Menu.\n";
	cout << "\t         " << n + 2 << ".Exit.";
	cout << "\n\n\t         Enter your selection: ";
	cin >> c;
	if (cin.fail()) {
		c=Library::fail("\n         Enter your selection: ");
	}
	while ((c <= 0 || c > n + 2)) {
		cout << "\n         Please select from the list: ";
		cin >> c;
		if (cin.fail()) {
			c=Library::fail("\n         Enter your selection: ");
		}
	}
    if (c == n + 1) return "Menu";
    if (c == n + 2) {
        return "-1";
    }
    return movie[c - 1].getId();
}
void MovieManager::RevenueSort(int l, int r, bool (*CompFunc)(int, int)) {
    if (this->movie == nullptr || this->length == 0) return;
    if (l >= r) return;
    int m = l + (r - l) / 2;
    int pivot = (*(this->movie + m)).getSales();
    int i = l, j = r;
    while (i <= j) {
        while (CompFunc(pivot, (*(this->movie + i)).getSales())) i++;
        while (CompFunc((*(this->movie + j)).getSales(), pivot)) j--;
        if (i <= j) {
            Movie temp = *(this->movie + i);
            *(this->movie + i) = *(this->movie + j);
            *(this->movie + j) = temp;
            i++;
            j--;
        }
    }
    if (l < j) RevenueSort(l, j, CompFunc);
    if (r > i) RevenueSort(i, r, CompFunc);
}
void MovieManager::showRevenues() {
    system("cls");
    cout << "\n\t\t\t\t\tBox office revenues:\n\n";
    for (int i = 0; i < this->length; i++) {
        cout << "\t\t" << left << setw(55) << (*(movie + i)).getName() << ": " << setw(20);
        string m = Library::printRevenues((*(movie + i)).getSales(), ".");
        Library::printLineColor(m, 2);
        cout << " vnd." << endl;
    }
}
Movie MovieManager::createMovie() {
    int year, duration, price;
    string name, type, content, time, actor, country, showtime, id;
    char cine;
    cout << "\t\tId: ";
    cin.ignore(32767, '\n');
    getline(cin, id);
    cout << "\t\tName: ";
    getline(cin, name);
    cout << "\t\tType: ";
    getline(cin, type);
    cout << "\t\tDuration: ";
    cin >> duration;
    if (cin.fail()) {
        Library::fail("\t\tDuration");
    }
    cout << "\t\tYear: ";
    cin >> year;
    if (cin.fail()) {
        Library::fail("\t\tYear");
    }
    cin.ignore(32767, '\n');
    cout << "\t\tCountry: ";
    getline(cin, country);
    cout << "\t\tContent: ";
    getline(cin, content);
    cout << "\t\tTime: ";
    getline(cin, time);
    cout << "\t\tActor: ";
    getline(cin, actor);
    int a[6][4];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < this->length; i++) {
        Movie p = *(movie + i);
        string c = p.getCine();
        int t2 = -1;
        if (c == "A") {
            t2 = 0;
        }
        else  if (c == "B") {
            t2 = 1;
        }
        else if (c == "C") {
            t2 = 2;
        }
        else if (c == "D") {
            t2 = 3;
        }
        stringstream s = (stringstream)p.getShowtime();
        while (s.good()) {
            string q;
            getline(s, q, ',');
            int t = -1;
            if (q == "8:15") {
                t = 0;
            }
            if (q == "11:10") {
                t = 1;
            }
            if (q == "14:15") {
                t = 2;
            }
            if (q == "17:05") {
                t = 3;
            }
            if (q == "19:25") {
                t = 4;
            }
            if (q == "22:20") {
                t = 5;
            }
            if (t != -1 && t2 != -1) {
                a[t][t2] = 0;
            }

        }
    }
    Library::printLineColor("\t\tCinema's Schedule", 3);
    cout << "\n\n";
    cout << "   ";
    for (int i = 0; i < 7; i++) {
        cout << "                ";
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0 && j != 0) {
                printf("%3c", j + 64);
            }
            else if (j == 0 && i != 0) {
                printf("%3d", i);
                cout << " ";
            }
            else {
                if (a[i - 1][j - 1] == 1) {
                    Library::printLineColor(" 1 ", 2);
                }
                else {
                    Library::printLineColor(" 0 ", 4);
                }
            }
        }
        cout << endl;
    }
    bool again = true;
    while (again) {
        cout << "\t\tCinema: ";
        cin.clear();
        cin >> cine;
        cine = toupper(cine);
        while (cine > 'D' || cine < 'A')
        {
            cout << "\t\tPlease choose A to D!" << endl << "\t\tCinema: ";
            cin >> cine;
            cine = toupper(cine);

        }
        cout << "\t\tShowtime: " << endl;
        cout << "\t\tSet 1: 8:15" << endl;
        cout << "\t\tSet 2: 11:10" << endl;
        cout << "\t\tSet 3: 14:15" << endl;
        cout << "\t\tSet 4: 17:05" << endl;
        cout << "\t\tSet 5: 19:25" << endl;
        cout << "\t\tSet 6: 22:20" << endl;
        cout << "\t\tEnter amount showtime: ";
        int sl;
        int q;
        cin >> sl;
        while ((sl <= 0 || sl > 6) || cin.fail()) {
            if (cin.fail()) {
                Library::fail("\t\tAmount of showtime");
            }
            cin.ignore(32767, '\n');
            cout << "\t\tPlease enter again: ";
            cin >> sl;
        }

        bool l = false;
        for (int i = 0; i < sl; i++) {

            cout << "\t\tEnter showtime (Number): ";
            cin >> q;
            if (cin.fail())
            {
                Library::fail("\t\tEnter showtime(Number) ");
            }

            while ((q <= 0 || q > 6)) {
                cout << "\t\tPlease select from the list: ";
                cin >> q;
            }
            if (q == 1) {
                showtime += "8:15";
            }
            else if (q == 2) {
                showtime += "11:10";
            }
            else if (q == 3) {
                showtime += "14:15";
            }
            else if (q == 4) {
                showtime += "17:05";
            }
            else if (q == 5) {
                showtime += "19:25";
            }
            else if (q == 6) {
                showtime += "22:20";
            }
            else {
                cout << "\t\tPlease select from the list! " << endl;
            }
            showtime += ",";
            int e;
            if (cine == 'A') {
                e = 0;
            }
            else  if (cine == 'B') {
                e = 1;
            }
            else if (cine == 'C') {
                e = 2;
            }
            else if (cine == 'D') {
                e = 3;
            }
            if (a[q - 1][e] == 0) {
                Library::printError("\t\tCinema " + string(1, cine) + " in set " + to_string(q) + " already taken! Please select again!");
                l = true;
                break;
            }
        }
        if (!l) again = false;

    }
    cout << "\t\tShowtime: " << showtime << endl;
    cout << "\t\tPrice: ";
    cin >> price;
    Movie m(id, name, type, content, time, year, duration, actor, country, string(1, cine), showtime, 0, price);
    return m;
}
void MovieManager::add() {
    Movie m = createMovie();
    addMovie(m);
}
void MovieManager::search()
{
    string name;
    cout << "\n\t\t\Enter the name that you want to search: ";
    char a[99];
    cin >> a;
    int k = -1;
    readData("Database\\Movie\\movie.txt");
    for (int i = 0; i < this->length; i++)
    {
        char Name[99];
        strcpy_s(Name, (movie + i)->getName().c_str());
        Library::Toupper(a);
        Library::Toupper(Name);
        if (strstr(Name, a))
        {
            (movie + i)->infMovie();
            k = 0;
        }
    }
    if (k == -1)
        cout << " No found this movie!" << endl;
}
Movie& MovieManager::operator[](const int i) {
    static Movie a;
    if (i >= 0 && i < this->length)
        return *(this->movie + i);
    else
        return a;
}
