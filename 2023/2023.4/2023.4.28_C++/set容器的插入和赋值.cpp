void printSet(set<int>&s){
? ? for(set<int>::iterator it = s.begin();it!=s.end();++it){
? ? ? ? cout << *it << " ";
? ? }
? ? cout << endl;
}
int main(){
? ? set<int> s1;
? ? s1.insert(40);
? ? s1.insert(30);
? ? s1.insert(20);
? ? s1.insert(10);
? ? s1.insert(10);//set容器不允许插入重复的元素
? ? printSet(s1);
? ? set<int> s2(s1);//拷贝构造
? ? printSet(s2);
? ? set<int> s3;
? ? s3 = s2;//赋值
? ? printSet(s3);
? ? system("pause");
? ? return 0;
}