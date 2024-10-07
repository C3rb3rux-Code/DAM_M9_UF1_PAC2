#include <iostream>
#include "./include/sqlite3.h"

using namespace std;

sqlite3* DB;

string rc;
int msg;
const char* siguiente;

int main() {

    string file = "./DDBB/chinook.db";

    int exist = sqlite3_open(file.c_str(), &DB);

    if (exist != SQLITE_OK)
    {
        cout << "Error al abrir la base\n";
    } else {
        cout << "Conexion completada\n";
    }

    sqlite3_stmt* stmt;

    rc = "SELECT * FROM employees;";

    msg = sqlite3_prepare(DB,rc.c_str(),rc.length(),&stmt, &siguiente);

    if (msg != SQLITE_OK)
    {
        cout << "Error en la consulta\n";
    }
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        cout << sqlite3_column_int(stmt, 0) << " | ";
        cout << sqlite3_column_text(stmt, 1) << " | ";
        cout << sqlite3_column_text(stmt, 2) << " | ";
        cout << sqlite3_column_text(stmt, 3) << " | ";
        cout << sqlite3_column_int(stmt, 4) << " | ";
        cout << sqlite3_column_int(stmt, 5) << " | ";
        cout << sqlite3_column_text(stmt, 6) << endl;
    }

    sqlite3_close;
    
}