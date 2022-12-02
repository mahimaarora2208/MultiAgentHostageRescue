/*
Copyright 2022 Naveen Mangla

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

/**
 * @file swat.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Functions discription for swat class
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022 Naveen Mangla
 */

#include <swat.hpp>


void Swat::move_to_base(){
    std::cout<<"Move to base"<<std::endl;
    // TODO: Inplementation Pending
}


void Swat::move_to_target(){
    std::cout<<"Move to target"<<std::endl;
    // TODO: Inplementation Pending
}

/**
 * @brief Provides counts for the number of threats remaining
 * 
 * @return int 
 */
int Swat::get_threat_count(){
    
    return this->threat_count;
}