class robot{
        private:
                int direction;
                int energy;
                int ID;
                int moved;
                void turnleft();
                void turnright();
                void forward(int &, int &);
        public:
                robot(int);
                void refresh() {moved=0;}
                void draw();
                void print();
                void move(int &, int &);
};



void robot::turnleft(){
energy--;
direction = (direction+3)%4;
}

void robot::turnright(){
energy--;
direction = (direction+1)%4;
}

void robot::forward(int &x, int &y){
        energy-=2;
        if(direction==0)
                y--;
        if(direction==2)
                y++;
        if(direction==1)
                x++;
        if(direction==3)
                x--;
}

robot::robot(int id){
        energy = 50;
        ID = id;
        moved = 0;
        direction = 0;
}

void robot::draw(){
	switch(direction){
	case 0:
	cout<<"^";
	break;
        case 2:
	cout<<"v";
        break;
        case 1:	
	cout<<">";
        break;
        case 3:
	cout<<"<";
        break;
}

}
void robot::print(){

        cout<<"ID" <<ID<<": Energy = "<<energy<<"   Direction = "<<direction;
}

void robot::move(int &x,int &y){
        if(moved==1)
                return;
        switch(rand()%6){
        case 0:
                turnleft();
                break;
        case 1:
                turnright();
                break;
        case 2:

        case 3:
                forward(x,y);
                break;
	case 4:
		forward(x,y);
                break;
	case 5:
		forward(x,y);
                break;
        default:
                cout<<"error in robot move."<<endl;
        }
        moved=1;
}

