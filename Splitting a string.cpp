int main()
{
std::string original;
cin>>original;
std::size_t index = (original.size()/2)+1;
std::string::iterator it = original.begin();

std::string part1(it, it + index);
std::string part2(it + index, original.end());
cout<<part1;
cout<<part1<<endl;
return 0;
}
