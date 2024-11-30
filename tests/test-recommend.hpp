#pragma once

#include "recommend.hpp"

#include <unistd.h>
#include <iostream>


namespace Tests {
    static void init_recommeder(Recommend::Recommender& recommender) 
    {
	recommender.history.update("echo");
	recommender.history.update("cd");

	recommender.history.update("echo");
	recommender.history.update("echo");

	sleep(1);
	recommender.history.update("cd");
    }

    
    bool test_recommend_mistype(void) 
    {
	Recommend::Recommender recommender;
	init_recommeder(recommender);

	std::cout << recommender.recommend("echz") << std::endl;
	

	return "echo" == recommender.recommend("echz");
    }

    
    bool test_recommend_mistype_long(void) 
    {
	Recommend::Recommender recommender;
	init_recommeder(recommender);
	
	return "echo" == recommender.recommend("echoz");
    }

    bool test_recommend_mistype_short(void) 
    {
	Recommend::Recommender recommender;
	init_recommeder(recommender);
	
	return "echo" == recommender.recommend("ech");
    }

}
