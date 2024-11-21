/*XOR Operation
 * 0 ^ x = x
 * 1 ^ bit = reverse bit
 * 
 * [0, 1, 2, 3] packets bante hai => en sb ka xor 0 hoga
 * 
 * 
 * [4, 5, 6, 7] = 0
 * packets ke first 3 ka ^ fourth one hoga =>
 * ex - 4 ^ 5 ^ 6 = 7  (n + 1)  kyoki agar 4, 5, 6 tino ka ^ ko 7 se ^ karne par 0 aata hai wahi aayege na
 * 
 * 
 * packets ke first 2 ka ^ 1 hota hai
 * 
 * formula => if(n % 4 == 3) then xor of all numbers till n = 0   [packet ban gaya]
 *            if(n % 4 == 0) then ^ of all numbers till n = n
 *            if(n % 4 == 1) then ^ --------------------- = 1
 *            if(n % 4 == 2) then ans = n + 1
 * 
 * [8, 9, 10, 11] ------- so on
 * 
 * 
 * agar mujhe kayi number ka xor karna hoga to sb ke sirf bits count karunga 
 * agar bits even huye sb me to xor = 0
 * like - 1 0 1 0
 *        0 1 0 1
 *        0 0 1 0
 *        1 1 0 1
 *      ==========
 *        0 0 0 0
 * 
 * haan abhi to bahut hi important hai bhai
 *   (a ^ b) = k
 *  then a ^ (a ^ b) = k ^ a
 *          b = k ^ a   also a = k ^ b   
 * 
 * =====
 *      left shift = multiply by 2 
 *      right shift = divide by 2
*/


/*
   very important propeties 

    1 ->  (a + b) = (a | b) + (a & b)
    general -> sum = OR + AND

    2 -> (a + b) = (a ^ b) + 2 * (a & b)
    general -> sum = xor + 2 * and

    3 -> (a | b) = (a ^ b) + (a & b)
            OR = xor + and

*/