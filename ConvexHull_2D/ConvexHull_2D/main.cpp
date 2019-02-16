//
//  main.cpp
//  ConvexHull_2D
//
//  Created by YouTooLife on 16/02/2019.
//  Copyright © 2019 YouTooLife. All rights reserved.
//

#include <stdio.h>
#include <vector>

#define VAR_T double


struct Point
{
    VAR_T x;
    VAR_T y;
    
    Point(VAR_T x, VAR_T y): x(x), y(y) { }
    
    bool operator== (const Point &p) const
    {
        return this->x == p.x && this->y == p.y;
    }
};



int main(int argc, const char * argv[]) {
    
    size_t n;
    std::vector<Point> points;
    
    // input... points
    FILE* f = 0;
    if ((f = fopen("input.txt", "r"))) {
        
        printf("reading file...\n");
        
        fscanf(f, "%ld", &n);
        
        for (size_t i = 0; i < n; ++i)
        {
            VAR_T x, y;
            fscanf(f, "%lf %lf", &x, &y);
            points.push_back(Point(x, y));
            //printf("%f %f\n", x, y);
        }
        fclose(f);
    }
    else {
        
        printf("Input points count: ");
    
        scanf("%ld", &n);
    
    for (size_t i = 0; i < n; ++i)
    {
        printf("\nInput X Y coords of (%ld) point: ", i+1);
        VAR_T x, y;
        scanf("%lf %lf", &x, &y);
        points.push_back(Point(x, y));
    }
    }
    
    // Find the lowest left point O(N) = N*log(N)
    std::sort(points.begin(), points.end(),
              [] (const Point &left, const Point &rigth) {
        if (left.y != rigth.y)
        {
            return left.y < rigth.y;
        }
        return left.x < rigth.x;
    });
    
    // delete duplicates
    points.erase(std::unique(points.begin(), points.end()), points.end());
    
    
    
    // sort by firt point by angle  O(N) = N*log(N)
    Point &fp = points[0];
    std::sort(points.begin()+1, points.end(),
              [&fp] (const Point &left, const Point &rigth) {
                  VAR_T dxL = left.x - fp.x;
                  VAR_T dyL = left.y - fp.y;
                  
                  VAR_T dxR = rigth.x - fp.x;
                  VAR_T dyR = rigth.y - fp.y;
                  
                  VAR_T pcp = dxL * dyR - dxR * dyL;
                  
                  if (pcp != 0) {
                        return pcp > 0;
                  }
                  else
                      return (dxL*dxL + dyL*dyL) < (dxR*dxR + dyR*dyR);
              });
    
    
    // Graham's algorithm : walking through the points  O(N) = N
    std::vector<Point> cHull;
    cHull.push_back(fp);
    cHull.push_back(points[1]);
    
    n = points.size();
    
    for (size_t i  = 2; i < n; ++i)
    {
        size_t hSize;
        while ((hSize = cHull.size()) > 1) {
            const Point& p0 = cHull[hSize-2];
            const Point& p1 = cHull[hSize-1];
            const Point& p2 = points[i];
            
            VAR_T dxL = p1.x - p0.x;
            VAR_T dyL = p1.y - p0.y;
            
            VAR_T dxR = p2.x - p1.x;
            VAR_T dyR = p2.y - p1.y;
            
            VAR_T pcp = dxL * dyR - dxR * dyL;
            if (pcp <= 0)
            {
                cHull.pop_back();
            }
            else
                break;
        }
        cHull.push_back(points[i]);
    }
    
    printf("Answer: \n");
    for (Point &p : cHull)
    {
        printf("%f %f\n", p.x, p.y);
    }
    
    return 0;
}
