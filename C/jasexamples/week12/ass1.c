int height, width;

if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
    return 1;
}
int pixels[height][width];

NOT available on all C compilers

What to do if not available?

Also, many functions looked like

fun(height, width, pixels, res_height, res_width, res_pixels)

How to make function calls simpler?


