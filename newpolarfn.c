int polar_info(double x, double y, double *radius, double *angle) {


	*radius = sqrt((x*x)+(y*y));
	*angle = atan(y/x);

    if (x < 0.0 && y > 0.0) {
        *angle += (M_PI/2);
    } else if (x < 0.0 && y < 0.0) {
        *angle += (M_PI);
    } else if (x > 0.0 && y < 0.0) {
        *angle += ((3*M_PI)/2);
    } else {
	   *angle = *angle;
    }
	if (x > 0.0 && y > 0.0) {
        return 1;
    } else if (x < 0.0 && y > 0.0) {
        return 2;
    } else if (x < 0.0 && y < 0.0) {
        return 3;
    } else if (x > 0.0 && y < 0.0) {
		return 4;
	} else if (x == 0. && y > 0.) {
        return -2;
    } else if (x < 0. && y ==0.) {
        return -1;
    } else if (x > 0. && y ==0.) {
        return -1;
    } else if (x == 0. && y < 0.) {
        return -2;
    } else if (x == 0. && y == 0.) {
        return 0;
    } else {
    	return 5;
    }
}