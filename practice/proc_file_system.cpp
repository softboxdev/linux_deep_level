#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void read_proc_filesystem() {
    // /proc - виртуальная файловая система
    // Содержит информацию о процессах и системе
    
    // Чтение информации о процессоре
    ifstream cpuinfo("/proc/cpuinfo");
    string line;
    
    cout << "Информация о процессоре:" << endl;
    for (int i = 0; i < 5 && getline(cpuinfo, line); i++) {
        cout << line << endl;
    }
    
    // Чтение информации о памяти
    ifstream meminfo("/proc/meminfo");
    cout << "\nИнформация о памяти:" << endl;
    for (int i = 0; i < 3 && getline(meminfo, line); i++) {
        cout << line << endl;
    }
    
    // Чтение информации о текущем процессе
    string pid = to_string(getpid());
    string stat_path = "/proc/" + pid + "/stat"; // статистика процесса
    string cmdline_path = "/proc/" + pid + "/cmdline"; // командна строка запуска процесса
    string exe_path = "/proc/" + pid + "/exe"; // символическая ссылка на испольняемый файл
    string environ_path = "/proc/" + pid + "/environ"; // переменные окружения
    string fd_path = "/proc/" + pid + "/fd"; // дескрипторы открытых файлов
    string maps_path = "/proc/" + pid + "/maps"; // карта памяти процесса
    string status_path = "/proc/" + pid + "/status"; // общая информация о процессе
    string smaps_path = "/proc/" + pid + "/smaps"; // детальная карта памяти


    
    ifstream proc_stat(stat_path);
    if (proc_stat) {
        cout << "\nИнформация о процессе " << pid << ":" << endl;
        getline(proc_stat, line);
        cout << line << endl;
    }
    ifstream proc_stat(cmdline_path);
    if (proc_stat) {
        cout << "\nИнформация о процессе " << pid << ":" << endl;
        getline(proc_stat, line);
        cout << line << endl;
    }
}

int main() {
    read_proc_filesystem();
    return 0;
}


