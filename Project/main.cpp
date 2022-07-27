#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


class Quiz
{
private:
    std::string ques;
    std::vector<std::string> choices;
    int choices_num;
    int answer;

    int answer_disp;


#define MAX_CHOICES_NUM 4

#define MAX_CHOICES_DISP_NUM 3

#define RET_NORMAL 0
#define RET_ERROR  -1

public:

    Quiz(): choices_num(0), answer(0) , answer_disp(0){}

    Quiz(const Quiz& q) {
        ques = q.ques;
        for(int i = 0; i< MAX_CHOICES_NUM; i++)	choices.push_back(q.choices[i]);
        choices_num = choices.size();
        answer = q.answer;
        answer_disp = answer;
    }

    ~Quiz() {}

    void Disp();

    std::string Write(bool isAnsDisp = true);

    int SetQuestion(std::string q_str);

    int SetChoices(std::string c_str);

    int SetAnsNo(int no);

    int GetChoicesMaxCount();

    int GetChoicesCount();

    bool CheckAns(int no);

    bool CheckData();

};


void Quiz::Disp()
{
    int*ch;
    int i = 0;

    srand((unsigned int)time(NULL));
    ch = new int[MAX_CHOICES_NUM];
    for(int i = 0; i<MAX_CHOICES_NUM; i++) ch[i] = i;


    while(1) {
        int r = rand()%MAX_CHOICES_NUM;
        if(r != answer) {
            ch[r] = MAX_CHOICES_NUM-1;
            ch[MAX_CHOICES_NUM-1] = r;
            break;
        }
    }

    for(i = 0; i<MAX_CHOICES_NUM; i++) {
        int r = rand()%MAX_CHOICES_DISP_NUM;
        int s = rand()%MAX_CHOICES_DISP_NUM;
        int tmp = ch[r];
        ch[r] = ch[s];
        ch[s] = tmp;
    }

    std::cout << "----------------------\n";
    std::cout << ques << "\n";

    for(i = 0; i<MAX_CHOICES_DISP_NUM; i++) {
        std::cout << i+1 << ":" << choices[ch[i]] << "\n";
        if(ch[i] == answer) answer_disp = i;
    }
    std::cout << "----------------------\n";
    std::cout << "input answer...." << std::endl;
    delete[] ch;
    return;
}



std::string Quiz::Write(bool isAnsDisp)
{
    std::string str;
    std::vector<std::string>::iterator it;
    str = ques;
    str += "\n";
    for(it = choices.begin(); it!=choices.end(); ++it) {
        str += *it;
        str += "\n";
    }
    if(isAnsDisp) {
        str += answer + '1';
        str += "\n";
    }
    return str;
}


int Quiz::SetQuestion(std::string q_str)
{
    ques = q_str;
    return RET_NORMAL;
}


int Quiz::SetChoices(std::string c_str)
{

    if(choices.size() >= MAX_CHOICES_NUM) return RET_ERROR;

    choices.push_back(c_str);
    return RET_NORMAL;
}

int Quiz::SetAnsNo(int no)
{
    answer = no-1;
    return answer;
}

int Quiz::GetChoicesMaxCount()
{
    return MAX_CHOICES_NUM;
}

int Quiz::GetChoicesCount()
{
    return choices.size();
}


bool Quiz::CheckAns(int no)
{
    return (answer_disp == no-1);
}


bool Quiz::CheckData()
{
    if(ques.length() <= 0) return false;
    if(choices.size() < MAX_CHOICES_NUM) return false;
    if(answer >= MAX_CHOICES_NUM) return false;
    if(answer < 0) return false;
    return true;
}


enum {
    CMD_NONE = 0,
    CMD_INITIAL,
    CMD_SAVE,
    CMD_LOAD,
    CMD_ADD,
    CMD_START,
    CMD_SHOW,
    CMD_MAX
};



int main(void)
{
    int num=0;
    std::vector<Quiz> quiz;
    std::vector<Quiz>::iterator it;
    std::string fn = "data.txt";

    const int MAX_QUIZ_NUM = 5;
    int quiz_num;
    int point = 0;

    while(1){

        std::cout << "- menu ----\n";
        std::cout << "1.Initial\n";
        std::cout << "2.Save\n";
        std::cout << "3.Load\n";
        std::cout << "4.Add Quiz\n";
        std::cout << "5.Start Quiz\n";
        std::cout << "6.Show All Quiz\n";
        std::cout << "others.Quit App\n";
        std::cout << "-----------" << std::endl;
        std::cout << "input cmd no..." << std::endl;


        std::cin  >> num;


        if(num <= CMD_NONE || num >= CMD_MAX)	break;


        switch(num)
        {

            case CMD_INITIAL:
                quiz.clear();
                break;

            case CMD_SAVE:
            {
                std::ofstream f;
                f.open(fn, std::ios::out);
                for(it = quiz.begin(); it != quiz.end(); ++it)
                    f << it->Write() << std::endl;
                f.close();
                break;
            }

            case CMD_LOAD:
            {

                std::ifstream f(fn, std::ios::in);
                if(!f) {
                    std::cerr << "File Open Error" << std::endl;
                    return -1;
                }


                std::string str;
                while(std::getline(f, str)) {
                    if(str.size() == 0) continue;
                    Quiz q;
                    q.SetQuestion(str);
                    while(q.GetChoicesCount() < q.GetChoicesMaxCount()) {
                        std::getline(f, str);
                        q.SetChoices(str);
                    }
                    std::getline(f, str);
                    q.SetAnsNo(stoi(str));
                    if(q.CheckData()) quiz.push_back(q);
                }
                f.close();
                break;
            }

            case CMD_ADD:
            {
                Quiz q;
                std::string str;
                int no;
                while(1){

                    while(1){
                        std::cout << "input question....\n";
                        std::cin  >> str;
                        if(str.size() <= 0) continue;
                        break;
                    }
                    q.SetQuestion(str);

                    while(1) {
                        std::cout << "input choices " << q.GetChoicesCount()+1 << "....\n";
                        std::cin  >> str;
                        if(str.size() <= 0) continue;
                        q.SetChoices(str);
                        if(q.GetChoicesCount() == q.GetChoicesMaxCount()) break;
                    }

                    while(1) {
                        std::cout << "input correct number ....\n";
                        std::cin  >> no;
                        if(no <= 0) continue;
                        if(no > q.GetChoicesMaxCount()) continue;
                        q.SetAnsNo(no);
                        break;
                    }

                    if(q.CheckData() == true) break;
                    else {
                        std::cout << "input Quiz data again" << std::endl;
                    }
                }

                quiz.push_back(q);
                break;
            }

            case CMD_START:
                int no;
                point = 0;
                quiz_num = (quiz.size() < MAX_QUIZ_NUM)? quiz.size() : MAX_QUIZ_NUM;

                std::random_shuffle(quiz.begin(), quiz.end());
                for(int i = 0; i<quiz_num; i++) {
                    quiz[i].Disp();
                    std::cin  >> no;
                    if(quiz[i].CheckAns(no) == true) {
                        std::cout << "Is the correct answer!!!" << std::endl;
                        point++;
                    }
                    else {
                        std::cout << "Is the incorrect answer..." << std::endl;
                    }
                }
                std::cout << "Your point is　" << point << " / " << quiz_num << std::endl;
                break;
            case CMD_SHOW:
                for(it = quiz.begin(); it != quiz.end(); ++it) {
                    std::cout << it->Write(false) << std::endl;
                }
                break;
            default:
                break;
        }
    }


    return 0;
}