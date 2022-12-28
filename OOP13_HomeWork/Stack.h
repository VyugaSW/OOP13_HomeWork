#pragma once
class Stacks {
	enum { EMPTY = -1, FULL = 50 };
	char st[FULL + 1];
	int top;
public:
	Stacks();
	void PushStack(char c);
	char PopStack();
	void ClearStack();
	bool IsEmptyStack();
	bool IsFullStack();
	int GetCountStack();
	char GetTopStack();
};

Stacks::Stacks() {
	
	top = EMPTY;
}

char Stacks::GetTopStack() {
	return st[top];
}

void Stacks::ClearStack() {
	top = EMPTY;
}

bool Stacks::IsEmptyStack() {
	return top == EMPTY;
}

bool Stacks::IsFullStack() {
	return top == FULL;
}

int Stacks::GetCountStack() {
	return top + 1;
}

void Stacks::PushStack(char c) {
	if (!IsFullStack())
		st[++top] = c;
}

char Stacks::PopStack() {
	if (!IsEmptyStack())
		return st[top - 1];
	else
		return 0;
}

