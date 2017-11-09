#include<iostream>
using namespace std;
struct point{
	float x, y;
};
int dir(point p1,point p2,point p3)
{
	float a=(p2.x-p1.x)*(p3.y-p1.y);
	float b=(p3.x-p1.x)*(p2.y-p1.y);
	return (a-b);
}
bool onsegment(point p1,point p2,point p3)
{
	if((min(p1.x,p2.x)<=p3.x&&max(p1.x,p2.x)>=p3.x)&&(min(p1.y,p2.y)<=p3.y&&max(p1.y,p2.y)>=p3.y))
     return true;
	else
	  return false;
}
bool seg_int(point p1,point p2,point p3,point p4)
{
	int d1=dir(p3,p4,p1);
	int d2=dir(p3,p4,p2);
	int d3=dir(p1,p2,p3);
	int d4=dir(p1,p2,p4);
	if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
	    return true;
	else if(d1==0&&onsegment(p3,p4,p1))
	    return true;
    else if(d2==0&&onsegment(p3,p4,p2))
	    return true;
    else if(d3==0&&onsegment(p1,p2,p3))
	   return true;
	else if(d4==0&&onsegment(p1,p2,p4))
	    return true;
    else
	   return false;		   				    
	    
}
int main()
{
	point p1,p2,p3,p4;
	cin>>p1.x>>p1.y;
	cin>>p2.x>>p2.y;
	cin>>p3.x>>p3.y;
	cin>>p4.x>>p4.y;
	if(seg_int(p1,p2,p3,p4))
	  cout<<"yes\n";
	  else
	  cout<<"No\n";
}
