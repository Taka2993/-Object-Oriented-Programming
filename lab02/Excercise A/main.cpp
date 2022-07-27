#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string& xml, const string& tag_name);

int main() {
    string page, line, location, temperature, input, output;
    ifstream file("weather.xml");

    while (getline(file, line)) {
        page.append(line);
        line.erase();
    }

    location = find_field(page, "location");
    temperature = find_field(page, "temp_c");

    cout << "Location: " << location << endl;
    cout << "Temperature: " << temperature << endl;
    }


string find_field(const string &xml, const string& tag_name)
{
    const string start_tag {"<" + tag_name + ">"};
    const string end_tag {"</" + tag_name + ">"};

    if (const size_t pos_start = xml.find(start_tag); pos_start != string::npos)
        if (const size_t pos_end = xml.find(end_tag, pos_start + start_tag.size()); pos_end != string::npos)
            return xml.substr(pos_start + start_tag.size(), pos_end - pos_start - start_tag.size());

    return "not found";
}