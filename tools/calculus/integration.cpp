// #include <cmath>

// void quad1_stiffness(
//     Equation &eq,                            // equation coefs
//     std::vector<std::vector<float>> &local,  // local matrix
//     float start,                             // elem left end
//     float end                                // elem right end
// )                               
// {
//     // integration by central quad rule
    
//     float h = end - start;

//     float quad_point = start + h / 2;

//     float p = eq.get_p(quad_point);
//     float r = eq.get_q(quad_point);
//     float s = eq.get_s(quad_point);
//     float q = eq.get_q(quad_point);

//     local[0][0] =  p - r - s + q;
//     local[0][1] = -p - r + s + q;
//     local[1][0] = -p + r - s + q;
//     local[1][1] =  p + r + s + q;
// }

// void quad1_power(
//     Equation &eq,
//     std::vector<float> local,
//     float start,
//     float end
// )
// {
//     float h = end - start;
    
//     float quad_point = start + h / 2;

//     local[0] = local[1] = h/2 * eq.get_f(quad_point);
// }
