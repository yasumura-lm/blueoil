#include <cstdlib>
#include <iostream>
#include "blueoil.hpp"

int test_tensor() {
    float tensor_data[][3] = {
			      {1, 2, 3},
			      {7, 8, 9}
    };
    float tensor_data2[][2] = {  // equals data, different shape.
			       {1, 2},
			       {3, 7},
			       {8, 9}
    };
    float tensor_data3[][3] = {  // equals shape, different data.
			       {1, 2, 3},
			       {7, 0, 9}
    };
    blueoil::Tensor tensor0({2, 3}, (float *) tensor_data);
    blueoil::Tensor tensor1({2, 3}, (float *) tensor_data);
    blueoil::Tensor tensor2({3, 2}, (float *) tensor_data2);  // shape diff
    blueoil::Tensor tensor3({2, 3}, (float *) tensor_data3);  // data diff
    // equal
    if ((! tensor0.allequal(tensor1)) || (! tensor0.allclose(tensor1))) {
	std::cerr << "tensor_test: tensor0 != tensor1" << std::endl;
	tensor0.dump();
	tensor1.dump();
	return EXIT_FAILURE;
    }
    // shape different
    if (tensor1.allequal(tensor2) || tensor1.allclose(tensor2)) {
	std::cerr << "tensor_test: tensor1 == tensor2" << std::endl;
	tensor1.dump();
	tensor2.dump();
	return EXIT_FAILURE;
     }
    // data different
    if (tensor1.allequal(tensor3) || tensor1.allclose(tensor3)) {
	std::cerr << "tensor_test: tensor1 == tensor3" << std::endl;
	tensor1.dump();
	tensor3.dump();
	return EXIT_FAILURE;
     }
    return EXIT_SUCCESS;
}


int main(void) {
    int status_code = test_tensor();
    std::exit(status_code);
}

