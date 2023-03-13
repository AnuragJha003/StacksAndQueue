class MinStack {
    int stack[10000];//NORMAL STACK FOR PUSH POP GG 
    int min[10000];//SUPPORTING STACK FOR MINIMUM ELMNT
    int topptr;
    int minptr;
public:
    MinStack() {
        topptr=-1;
        minptr=-1;
    }//INITILASE WITH -1 
    
    void push(int x) {
        if(topptr>10000){
            return;
        }//EXCEEDS SIZE 
        stack[++topptr]=x;//PUSH IN THE STACK 
        if(minptr>=0){//IF MIN STACK IS NON EMPTY
            if(min[minptr]>x){//VALUE OF COMING X IS SMALLER TOH PUSH IN MIN STACK TOO 
                min[++minptr]=x;
            }
            else{//ELSE NOT SMALLERR
                min[minptr+1]=min[minptr];
                minptr+=1;//JUST FILL THE MIN STACK AGAIN WITH THE SAME SMALLEST ELMNT WHICH WAS PREVIOUSLY PRESENT
            }
        }
        else{
            min[++minptr]=x;//IF EMPTY THEN TOH PUSH 
        }
    }
    
    void pop() {
        if(topptr<0){
            return;
        }
        topptr-=1;
        minptr-=1;
    }//POP SUBTRACTING 1 FROM BOTH THE TOP POINTERS 
    
    int top() {
        return stack[topptr];
    }//TOP ELMNT RETURNED 
    int getMin() {
        return min[minptr];//MIN ELMNT OF THE STACK STORED IN THE TOP OF THIS SECONDARY STACK 
    }
};
