#include<bits/stdc++.h>
using std::string;
using std::cin;
using std::cout;
typedef long long LL;
const int N=100+5;
int Q;
struct Type{
	std::vector<std::pair<string,Type*>> m;
	LL size;
	int align;
}buffer[N],*Byte,*Short,*Int,*Long;
int ctype;
Type*nw_type(){
	ctype++;
	return &buffer[ctype];
}
std::map<string,Type*>type;
std::vector<std::pair<string,Type*>>vars;
char tmp[21];
inline LL align_to(LL x,int y){
	return x%y?x-x%y+y:x;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	Byte=nw_type(),Short=nw_type();
	Int=nw_type(),Long=nw_type();
	Byte->size=Byte->align=1;
	Short->size=Short->align=2;
	Int->size=Int->align=4;
	Long->size=Long->align=8;
	type["byte"]=Byte,type["short"]=Short;
	type["int"]=Int,type["long"]=Long;
	cin>>Q;
	while(Q--){
		int t;
		cin>>t;
		if(t==1){
			string name;
			int cnt;
			cin>>name>>cnt;
			Type*now=nw_type();
			type[name]=now;
			while(cnt--){
				string typname,varname;
				cin>>typname>>varname;
				Type*typ=type[typname];
				now->m.push_back({varname,typ});
				now->size=align_to(now->size,typ->align)+typ->size;
				now->align=std::max(now->align,typ->align);
			}
			now->size=align_to(now->size,now->align);
			std::cout<<now->size<<' '<<now->align<<'\n';
		}else if(t==2){
			string typname,varname;
			cin>>typname>>varname;
			LL addr=0;
			for(int i=0;i<(int)vars.size();i++)
				addr=align_to(addr,vars[i].second->align),addr+=vars[i].second->size;
			addr=align_to(addr,type[typname]->align);
			std::cout<<addr<<'\n';
			vars.push_back({varname,type[typname]});
		}else if(t==3){
			LL addr=0;
			int now=0,nxtnow=0;
			string buf;
			cin>>buf;
			sscanf(buf.c_str()+now,"%[a-z]%n",tmp,&nxtnow),now+=nxtnow;
			string varname=tmp;
			Type*tp;
			for(int i=0;i<(int)vars.size();i++){
				addr=align_to(addr,vars[i].second->align);
				if(vars[i].first!=varname)
					addr+=vars[i].second->size;
				else{
					tp=vars[i].second;
					break;
				}
			}
			while(sscanf(buf.c_str()+now,".%[a-z]%n",tmp,&nxtnow)==1){
				now+=nxtnow;
				addr=align_to(addr,tp->align);
				string name=tmp;
				for(int i=0;i<(int)tp->m.size();i++){
					addr=align_to(addr,tp->m[i].second->align);
					if(tp->m[i].first!=name)
						addr+=tp->m[i].second->size;
					else{
						tp=tp->m[i].second;
						break;
					}
				}
			}
			std::cout<<addr<<'\n';
		}else{
			LL addr,now_addr=0;
			bool flag=true;
			string ans;
			cin>>addr;
			Type*now=0;
			for(int i=0;i<(int)vars.size();i++){
				now_addr=align_to(now_addr,vars[i].second->align);
				if(addr<now_addr){
					flag=false;
					break;
				}
				if(addr>=now_addr+vars[i].second->size)
					now_addr+=vars[i].second->size;
				else{
					ans+=vars[i].first;
					now=vars[i].second;
					break;
				}
			}
			if(!now)
				flag=false;
			while(flag&&!now->m.empty()){
				now_addr=align_to(now_addr,now->align);
				if(addr<now_addr){
					flag=false;
					break;
				}
				bool fl=false;
				for(int i=0;i<(int)now->m.size();i++){
					now_addr=align_to(now_addr,now->m[i].second->align);
					if(addr<now_addr){
						flag=false;
						break;
					}
					if(addr>=now_addr+now->m[i].second->size)
						now_addr+=now->m[i].second->size;
					else{
						ans+="."+now->m[i].first;
						now=now->m[i].second;
						fl=true;
						break;
					}
				}
				if(!fl){
					flag=false;
					break;
				}
			}
			if(flag)
				cout<<ans<<'\n';
			else
				cout<<"ERR"<<'\n';
		}
	}
	return 0;
}
