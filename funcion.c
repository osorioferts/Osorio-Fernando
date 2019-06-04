//void __main(void)
//{ }

long funcion(long A,long B)
{
	long ret=B;
	__asm__ __volatile__("movl %0, %%eax ":"=m"(A));
	__asm__ __volatile__("movl %0, %%ebx ":"=m"(B));
	__asm__ __volatile__("xchgl %%eax, %0":"=m"(ret));
	return ret;
}

int main(){
	long a=20, b=40;
	return funcion(a,b);
}
