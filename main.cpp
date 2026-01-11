#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main() {
    string ffmpeg_loc = ".\\ffmpeg\\bin\\ffmpeg.exe";
    string format;
    string song_loc;
    string command;
    string out_song_name;
    string out_loc;

    cout << "请将FFmpeg的文件夹改名为ffmpeg并放入程序所在的目录"<<endl;
    system("pause");
    cout << "请输入音视频源文件完整路径: ";
    getline(cin, song_loc);

    cout << "请输入你想要转换的格式: ";
    cin >> format;

    cout << "请输入输出的音视频文件名: ";
    cin >> out_song_name;

    cout << "请输入输出的音视频文件完整路径（不含空格）: ";
    cin >> out_loc;


    if (out_loc[out_loc.size()] == '\\') {
        command = ffmpeg_loc + " -i \"" + song_loc + "\" \"" + out_loc + out_song_name + '.' + format + "\"";
    }
    else {
        command = ffmpeg_loc + " -i \"" + song_loc + "\" \"" + out_loc + '\\' + out_song_name + "." + format + "\"";
    }

    //command = ffmpeg_loc + " -i \"" + song_loc + "\" \"" + out_song_name + "." + format + "\"";

    cout << "\n即将执行命令: " << command << endl;
    system("pause");

    system(command.c_str());

    cout << "\n转换完成，按任意键退出\n";
    cin.ignore();
    cin.get();

    return 0;
}
