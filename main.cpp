#include <iostream>
#include <string>
#include <stdlib.h> 
#include <math.h>
#include <Eigen/Dense>

#define PN 50//�ɱ���ĵ����Ŀ 
#define LN 50//�ɱ����ߵ���Ŀ 
#define RN 50//�ɱ��������ε���Ŀ 
#define PI 3.1415926

using namespace Eigen;
using namespace std;

void add ();
void addPoint();
void addLine();
void addRect();
void move();
void rotate();



//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ�  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  

class Point {
    
    private :
        Vector2d v;    
        string name;    
    public:
        
        //���캯��
        Point(Vector2d v1){
            v = v1;
        }
        
        Point(Vector2d v1 , string pname) {
            v = v1;
            name = pname;
        } 
        Point() {};
        
        //���õ��x��y���� 
        void setPoint(Vector2d v1){
            v = v1;
        }
                
        
        Vector2d getPoint() {
            return v;
        }
        
        string getName() {
            return name;
        }
        
        void setName(string pname) {
            name = pname;
        }
};

class Line {
    private :
        Vector2d v1;
        Vector2d v2;
        string name;
        
    public :
        //���캯��
        Line() {};
         
        void setLine(Vector2d vv1,Vector2d vv2) {
            v1 = vv1;
            v2 = vv2;
        }
        
        Vector2d getStartPoint() {
            return v1;
        }
        
        Vector2d getEndPoint() {
            return v2;
        }
        
        void setName(string lname) {
            name = lname;
        }
        
        string getName() {
            return name;
        }
        
        
};

class Rect {
    private :
        Vector2d v1;
        Vector2d v2;
         Vector2d v3;
         string name;
         
    public:
        
        Rect() {};
        
    void setRect(Vector2d vv1,Vector2d vv2,Vector2d vv3) {
        v1 = vv1;
        v2 = vv2;
        v3 = vv3;
    }
    
    Vector2d getPoint1() {
        return v1;
    }
    
    Vector2d getPoint2() {
        return v2;
    }
    
    Vector2d getPoint3() {
        return v3;
    }
    
    void setName(string rname) {
        name = rname;
    }
    
    string getName() {
        return name;
    }
};

string a[5];
int pcnt = 0;
Point point[PN]; 
int lcnt = 0;
Line line[LN];
int rcnt = 0;
Rect rect[RN];


int main(int argc,char *argv[]) {
    
    while(1) {
        string str ; 
        getline(cin,str);//���������е��ַ��� 
         
        for(int i=0,j=0;i<str.size();i++) {
            int pos;
            pos = str.find(' ',i);
            if(pos!=std::string::npos) {
                a[j] = str.substr(i,pos-i);
                j++;
                i=pos;
            } else {
                a[j] = str.substr(i,str.size()-i);
                break;
            }
            
         }
         
         if(a[0]=="move") {
             move();
        } else if(a[0]=="rotate") {
            rotate();
        } else {
            add();
        }
    }
    
}

void add() {
    if(a[1]=="1") {
        addPoint();
    } else if(a[1]=="2") {
        addLine();
    } else if(a[1]=="3") {
        addRect();
    } else {
        cout<<"input error"<<endl;
    }
    
}

void addPoint() {
    Vector2d v;
    string m1,m2; 
    string s = a[2];
    double x,y;
    int pos;
    pos=s.find(',',0);
    if(pos!=std::string::npos) {
        m1 = s.substr(0,pos);
        m2 = s.substr(pos+1,s.size()-pos);
        x = stringToNum<double>(m1);
        y = stringToNum<double>(m2);
     } else {
         cout<<"direction error please write like this"<<endl;
         cout<<"p2 1 5,6"<<endl;
         exit(0); 
     }
     v<<x,y;
     
    point[pcnt].setPoint(v);
    point[pcnt].setName(a[0]);
    pcnt++;
    cout<<"add a dot :"<<a[0]<<endl;
    cout<<"location is:"<<v.transpose()<<endl; 
    
}

void addLine() {
    Vector2d v1,v2;
    string m1,m2,m3,m4;
    string s1 = a[2];
    string s2 = a[3];
    double x1,x2,y1,y2;
    int pos1,pos2;
        pos1=s1.find(',',0);
        
    if(pos1!=std::string::npos) {
        m1 = s1.substr(0,pos1);
        m2 = s1.substr(pos1+1,s1.size()-pos1);
        x1 = stringToNum<double>(m1);
        y1 = stringToNum<double>(m2);
     } else {
         cout<<"direction error please write like this"<<endl;
         cout<<"l1 2 1,2 3,4"<<endl;
         exit(0); 
    }
    
    pos2=s2.find(',',0);
    if(pos2!=std::string::npos) {
        m3 = s2.substr(0,pos2);
        m4 = s2.substr(pos2+1,s2.size()-pos2);
        x2 = stringToNum<double>(m3);
        y2 = stringToNum<double>(m4);
     } else {
         cout<<"direction error please write like this"<<endl;
         cout<<"l1 2 1,2 3,4"<<endl;
         exit(0); 
    }
    
    v1<<x1,y1;
    v2<<x2,y2;
    line[lcnt].setLine(v1,v2);
    line[lcnt].setName(a[0]);
    lcnt++;
    cout<<"add a line:"<<a[0]<<endl;
    cout<<"�������:"<<v1.transpose()<<endl;
    cout<<"�յ�����:"<<v2.transpose()<<endl; 
}

void addRect() {
    Vector2d v1,v2,v3;
    string m1,m2,m3,m4,m5,m6;
    string s1 = a[2];
    string s2 = a[3];
    string s3 = a[4];
    double x1,x2,x3,y1,y2,y3;
    int pos1,pos2,pos3;
    
    pos1=s1.find(',',0);    
    if(pos1!=std::string::npos) {
        m1 = s1.substr(0,pos1);
        m2 = s1.substr(pos1+1,s1.size()-pos1);
        x1 = stringToNum<double>(m1);
        y1 = stringToNum<double>(m2);
     } else {
         cout<<"ָ����������Ҫ��ӵ��밴�����½ṹ���룺"<<endl;
         cout<<"l1 2 1,2 3,4 5,6"<<endl;
         exit(0); 
    }
    
    pos2=s2.find(',',0);
    if(pos2!=std::string::npos) {
        m3 = s2.substr(0,pos2);
        m4 = s2.substr(pos2+1,s2.size()-pos2);
        x2 = stringToNum<double>(m3);
        y2 = stringToNum<double>(m4);
     } else {
         cout<<"ָ����������Ҫ��ӵ��밴�����½ṹ���룺"<<endl;
         cout<<"l1 2 1,2 3,4"<<endl;
         exit(0); 
    }
    
    pos3=s3.find(',',0);
    if(pos3!=std::string::npos) {
        m5 = s3.substr(0,pos3);
        m6 = s3.substr(pos3+1,s3.size()-pos3);
        x3 = stringToNum<double>(m5);
        y3 = stringToNum<double>(m6);
     } else {
         cout<<"ָ����������Ҫ��ӵ��밴�����½ṹ���룺"<<endl;
         cout<<"l1 2 1,2 3,4 5,6"<<endl;
         exit(0); 
    }
    
    v1<<x1,y1;
    v2<<x2,y2;
    v3<<x3,y3;
    rect[rcnt].setRect(v1,v2,v3);
    rect[rcnt].setName(a[0]);
    rcnt++;
    cout<<"add a rectangle:"<<a[0]<<endl;
    cout<<"�˵�һ����Ϊ��"<<v1.transpose()<<endl;
    cout<<"�˵������Ϊ��"<<v2.transpose()<<endl;
    cout<<"�˵�������Ϊ��"<<v3.transpose()<<endl;
     
}

void move() {
    string s;
    s = a[1];
    Vector2d v;
    bool find = false;
    string s1 = a[2];
    double x,y;
    int pos;
    string m1,m2;
    
    pos=s1.find(',',0);
    if(pos!=std::string::npos) {
        m1 = s1.substr(0,pos);
        m2 = s1.substr(pos+1,s.size()-pos);
        x = stringToNum<double>(m1);
        y = stringToNum<double>(m2);
     } else {
         cout<<"ָ����������Ҫ��ӵ��밴�����½ṹ���룺"<<endl;
         cout<<"move XX 2,3"<<endl;
         exit(0); 
     }
     v<<x,y;
    
    for(int i=0;i<PN;i++) {
        if(point[i].getName()==s) {
            find = true;
            Vector2d v1 = point[i].getPoint();
             v1=v1+v;
             cout<<s<<"ƽ�ƺ�ĵ������:"<<v1.transpose()<<endl;    
        } 
    }
    
    for(int i=0;i<LN;i++) {
        if(line[i].getName()==s) {
            find = true;
            Vector2d v1 = line[i].getStartPoint();
            Vector2d v2 = line[i].getEndPoint();
             v1 = v1+v;
             v2 = v2+v; 
             cout<<"ֱ��"<<s<<"ƽ�ƺ���������:"<<v1.transpose()<<endl;
             cout<<"ֱ��"<<s<<"ƽ�ƺ��յ������:"<<v2.transpose()<<endl;    
        } 
    }
    
    for(int i=0;i<RN;i++) {
        if(rect[i].getName()==s) {
            find = true;
            Vector2d v1 = rect[i].getPoint1();
            Vector2d v2 = rect[i].getPoint2();
            Vector2d v3 = rect[i].getPoint3();
             v1 = v1+v;
             v2 = v2+v; 
             v3 = v3+v;
             cout<<"������"<<s<<"��1ƽ�ƺ������:"<<v1.transpose()<<endl;
             cout<<"������"<<s<<"��2ƽ�ƺ������:"<<v2.transpose()<<endl;
             cout<<"������"<<s<<"��3ƽ�ƺ������:"<<v2.transpose()<<endl;    
        } 
    }
    
    if(find==false) {
        cout<<"û���ҵ���Ӧ�ĵ�����"<<endl; 
    }
}

void rotate() {
    string s;
    string s1 = a[2];
    s = a[1];
    MatrixXd rot(2,2);
    bool find = false;
    double deg,avg;
    deg = stringToNum<double>(s1);
    avg = deg*PI/180;
    rot(0,0)=cos(avg);
    rot(0,1)=sin(avg);
    rot(1,0)=-sin(avg);
    rot(1,1)=cos(avg);
   for(int i=0;i<PN;i++) {
        if(point[i].getName()==s) {
            find = true;
            Vector2d v1 = point[i].getPoint();
             v1=rot*v1;
             cout<<"��"<<s<<"��ԭ����ת�������Ϊ:"<<v1.transpose()<<endl;    
        } 
    }

    for(int i=0;i<LN;i++) {
        if(line[i].getName()==s) {
            find = true;
            Vector2d v1 = line[i].getStartPoint();
            Vector2d v2 = line[i].getEndPoint();
             v1 = rot*v1;
             v2 = rot*v2; 
             cout<<"ֱ��"<<s<<"��ת����������:"<<v1.transpose()<<endl;
             cout<<"ֱ��"<<s<<"��ת���յ������:"<<v2.transpose()<<endl;    
        } 
    }    
    
        for(int i=0;i<RN;i++) {
        if(rect[i].getName()==s) {
            find = true;
            Vector2d v1 = rect[i].getPoint1();
            Vector2d v2 = rect[i].getPoint2();
            Vector2d v3 = rect[i].getPoint3();
             v1 = rot*v1;
             v2 = rot*v2; 
             v3 = rot*v3;
             cout<<"������"<<s<<"��1��ת�������:"<<v1.transpose()<<endl;
             cout<<"������"<<s<<"��2��ת�������:"<<v2.transpose()<<endl;
             cout<<"������"<<s<<"��3��ת�������:"<<v2.transpose()<<endl;    
        } 
    }
    
    if(find==false) {
        cout<<"û���ҵ���Ӧ�ĵ����棬������ӵ����棡"<<endl;
    } 
}
