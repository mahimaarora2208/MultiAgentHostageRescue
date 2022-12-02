
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
 * @brief Threat class for threat bots
 * 
 */
# include <base.hpp> // for base class
class Swat: public BaseClass {
    private:
        std::pair<const int, const int> base = std::make_pair(0,0); // base location
        int threat_count; // number of threats remaining
    
    public:
        Swat() = default;
        void move_to_target();  // move to target
        void move_to_base();   // move to base
        int get_threat_count(); // get threat count

        // ! This is not complete

};