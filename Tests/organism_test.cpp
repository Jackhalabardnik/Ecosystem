#include <catch.hpp>
#include <organism.cpp>
#include <iostream>

using tuple_int = std::tuple<int,int>;

bool matchV(std::vector<tuple_int > v1, std::vector<tuple_int > v2)
{
	if(v1.size() != v2.size())
	{
		std::cout << "v1 != v2 : " << v1.size() << " != " << v2.size() << std::endl;
		return false;
	}
	for(unsigned int i=0;i < v1.size(); i++)
	{
		if(std::get<0>(v1[i]) != std::get<0>(v2[i]) || std::get<1>(v1[i]) != std::get<1>(v2[i]))
		{
			std::cout << "i " << i << " v1[i] != v2[i] : " << std::get<0>(v1[i]) << " != " << std::get<0>(v2[i]) << " v " << std::get<1>(v1[i]) << " != " << std::get<1>(v2[i]) << std::endl;
			return false;
		}
	}
	
	return true;
}

class OrganismTest : public Organism
{
public:
	std::vector<tuple_int > search_for_neighbourhood(tuple_int position, tuple_int ecosystem_size)
	{
		return Organism::search_for_neighbourhood(position, ecosystem_size);
	}
	
	virtual void take_action(std::vector<std::vector<std::shared_ptr<Organism> > > ecosystem, std::tuple<int,int> position)
	{
		
	}
};


TEST_CASE("Organism propely finds his neighbourhood", "[OrganismTests]")
{
	OrganismTest org;
	SECTION("LEFT_UP")
	{
		tuple_int position(0,0), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(1,0));
		vec.push_back(tuple_int(1,1));
		vec.push_back(tuple_int(0,1));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("LEFT_DOWN")
	{
		tuple_int position(3,0), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(2,0));
		vec.push_back(tuple_int(2,1));
		vec.push_back(tuple_int(3,1));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("RIGHT_UP")
	{
		tuple_int position(0,3), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(1,3));
		vec.push_back(tuple_int(1,2));
		vec.push_back(tuple_int(0,2));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("RIGHT_DOWN")
	{
		tuple_int position(3,3), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(2,3));
		vec.push_back(tuple_int(2,2));
		vec.push_back(tuple_int(3,2));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("RIGHT")
	{
		tuple_int position(2,3), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(1,3));
		vec.push_back(tuple_int(1,2));
		vec.push_back(tuple_int(3,3));
		vec.push_back(tuple_int(3,2));
		vec.push_back(tuple_int(2,2));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("LEFT")
	{
		tuple_int position(2,0), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(1,0));
		vec.push_back(tuple_int(1,1));
		vec.push_back(tuple_int(3,0));
		vec.push_back(tuple_int(3,1));
		vec.push_back(tuple_int(2,1));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("DOWN")
	{
		tuple_int position(3,1), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(2,1));
		vec.push_back(tuple_int(2,2));
		vec.push_back(tuple_int(2,0));
		vec.push_back(tuple_int(3,2));
		vec.push_back(tuple_int(3,0));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("UP")
	{
		tuple_int position(0,1), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(1,1));
		vec.push_back(tuple_int(1,2));
		vec.push_back(tuple_int(1,0));
		vec.push_back(tuple_int(0,2));
		vec.push_back(tuple_int(0,0));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	} 
	
	SECTION("MIDDLE")
	{
		tuple_int position(1,1), size(4,4);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(0,1));
		vec.push_back(tuple_int(0,2));
		vec.push_back(tuple_int(0,0));
		vec.push_back(tuple_int(2,1));
		vec.push_back(tuple_int(2,2));
		vec.push_back(tuple_int(2,0));
		vec.push_back(tuple_int(1,2));
		vec.push_back(tuple_int(1,0));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	}
	
	SECTION("LINE")
	{
		tuple_int position(0,1), size(1,3);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(0,2));
		vec.push_back(tuple_int(0,0));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	}
	
	SECTION("LINE_L_END")
	{
		tuple_int position(0,0), size(1,3);
		std::vector<tuple_int > vec;
		vec.push_back(tuple_int(0,1));
		CHECK(matchV(org.search_for_neighbourhood(position, size), vec));
	}
}