#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Stackk {
	private:
		int arr[5];
		int top = -1;
	public:
		void push(int n){
			arr[++top] = n;
		}
		void pop(){
			top --;
		}
		int getTop(){
			return arr[top];
		}
		int size(){
			return top +1;
		}
		bool isEmpty(){
			if (top != -1) return false;
			return true;
		}
};

class Queuee {
	private:
		int front = 0;
		int rear = 0;
		int a[5];
		int n =5;
	public:
	void push(int x){
		a[rear%n] = x;
		rear++;
	}
	void pop(){
		a[front%n] = -1;
		front ++;
	}
	int top(){
		return a[front%n];
	}
};	


class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};




class Queue {
  stack < int > input, output;
  
  // Push elements in queue
  void Push(int data) {
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input
    cout << "The element pushed is " << data << endl;
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }
  // Pop the element from the Queue
  int Pop() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = input.top();
    input.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return input.top();
  }
  // Return the size of the Queue
  int size() {
    return input.size();
  }
};


bool validParanthesis(string s){
	stack<char>st;
			bool flag = false;

	for(int i=0;i<s.size();i++){
		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
			st.push(s[i]);
		}
		else{
			if(st.empty()) return false;
			char c = st.top();	
			st.pop();
			if( (s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') ){
				flag = true;
			}else
				flag =  false;

			
		}
	}
	// if(st.empty()) return true;
	// else return false;
	return flag;
}

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};



int main(){
//1:
		//	implement stack using arrays
//	Stackk myStack ;
//	myStack.push(5);
//	int top = myStack.getTop();
//	cout<<"top is: "<<top<<endl;

// 2:
		// implement queue using arrays
//	Queuee myQ;
//	myQ.push(5);
//	int top = myQ.top();
//	cout<<"top is : "<<top<<endl;

// 3:
		//implement stack using queue
// 	Stack s;
//	  s.Push(3);
//	  s.Push(2);
//	  s.Push(4);
//	  s.Push(1);
//	  cout << "Top of the stack: " << s.Top() << endl;

// 4:
		// implement queue using stack
//   Queue q;
//   q.Push(3);
//   q.Push(4);
//   cout << "The element poped is " << q.Pop() << endl;
//   q.Push(5);  
//   q.Push(4);

// 5:
		// valid paranthesis
//		string s = "(]";
//		bool ans = validParanthesis(s);
//		ans == true ? cout<<" valid " : cout<<" Invalid ";

// 6:
		// design min stack
 return 0;
}
