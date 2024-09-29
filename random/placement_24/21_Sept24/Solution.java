class Point2D {
    public int x;
    public int y;

    public Point2D(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int solution(Point2D[] points, int perimeter) {
        int maxPoints = 0;

        int requiredSum = perimeter / 2;

        for (int x1 = -10; x1 <= 10; x1++) {
            for (int y1 = -10; y1 <= 10; y1++) {
                for (int width = 1; width <= 20; width++) {
                    int height = requiredSum - width;

                    if (height <= 0) {
                        continue;  
                    }

                    int x2 = x1 + width;
                    int y2 = y1 + height;

                    int count = 0;
                    for (Point2D point : points) {
                        if (point.x >= x1 && point.x <= x2 && point.y >= y1 && point.y <= y2) {
                            count++;
                        }
                    }

                    maxPoints = Math.max(maxPoints, count);
                }
            }
        }

        return maxPoints;
    }

    public static void main(String[] args) {
        // Create test points
        Point2D[] points = {
            new Point2D(-2, -1),
            new Point2D(-2, 0),
            new Point2D(-2, 1),
            new Point2D(-3, 3),
            new Point2D(-2, 3),
            new Point2D(-1, 3)
        };

        // Create an instance of Solution
        Solution solution = new Solution();
        
        // Test with different perimeter values
        int[] perimeters = {4};

        for (int perimeter : perimeters) {
            int maxPoints = solution.solution(points, perimeter);
            System.out.println("Max points inside rectangle with perimeter " + perimeter + ": " + maxPoints);
        }
    }
}

