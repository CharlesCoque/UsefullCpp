template<typename T>
struct Simplifier
{
	using type = T;
};

template<typename T>
struct Check;

int main()
{
	//Same as void (*)(), wich is a pointer to a parameterless function with no return
	Check< Simplifier<void()>::type* > f; 
}
