#include "ThreeDGridMap.h"
#include "PointCloud.h"
#include "Point.h"



// ThreeDGridMap is a class that represents a 3D grid map
// It stores a 3D array of boolean values, which represent whether each grid cell is occupied or not
// It also stores the grid size and the depth (number of cells in each dimension) of the map

// The constructor initializes the map with the specified depth and fills all the cells with false (unoccupied)
ThreeDGridMap::ThreeDGridMap(int depth, float gridSize)
    : depth(depth), gridSize(gridSize)
{
    // Initialize the map with the specified depth
    fill(&map[0][0][0], &map[0][0][0] + depth * depth * depth, false);
}

// insertPointCloud inserts a point cloud into the map
// It does this by iterating through all the points in the point cloud and inserting each one into the map individually
void ThreeDGridMap::insertPointCloud(PointCloud& pc)
{
    for (int i = 0; pc.pointNumber; i++) {
        insertPoint(pc.points[i]);
    }
}

// insertPoint inserts a single point into the map
// It converts the point's coordinates into grid indices and sets the corresponding cell to true (occupied)
void ThreeDGridMap::insertPoint(Point& p)
{
    int x = static_cast<int>(p.x / gridSize);
    int y = static_cast<int>(p.y / gridSize);
    int z = static_cast<int>(p.z / gridSize);


    // Only insert the point if it falls within the bounds of the map
    if (x >= 0 && x < depth && y >= 0 && y < depth && z >= 0 && z < depth) {
        map[x][y][z] = true;
    }
}

// getGrid returns the value of the cell at the specified indices
// If the indices are out of bounds, it returns false
bool ThreeDGridMap::getGrid(int x, int y, int z) const
{
    if (x < 0 || x >= depth || y < 0 || y >= depth || z < 0 || z >= depth) {
        return false;
    }


    return map[x][y][z];
}

// loadMap loads a map from a file with the specified name
// It reads the grid size and depth from the file, and then the values of all the cells in the map
// If the file cannot be opened, it returns false
bool ThreeDGridMap::loadMap(const std::string& fileName)
{
    std::ifstream in(fileName);


    if (!in.is_open()) {
        return false;
    }

    in >> gridSize;
    in >> depth;

    int value;

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                value = map[i][j][k] ? 1 : 0;
                in >> value;
            }
        }
    }

    return true;
}

// saveMap saves the map to a file with the specified name
// It writes the grid size and depth to the file, and then the values of all the cells in the map
// If the file cannot be opened,it returns false
bool ThreeDGridMap::saveMap(const std::string& fileName)
{
    std::ofstream out(fileName);
    if (!out.is_open()) {
        return false;
    }


    out << gridSize << '\n';
    out << depth << '\n';

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                out << map[i][j][k] << ' ';
            }
            out << '\n';
        }
    }

    return true;
}

// setGridSize sets the size of each grid cell in the map
void ThreeDGridMap::setGridSize(float size)
{
    gridSize = size;
}

// getGridSize returns the size of each grid cell in the map
float ThreeDGridMap::getGridSize() const
{
    return gridSize;
}

// setDepth sets the number of cells in each dimension of the map
void ThreeDGridMap::setDepth(int d)
{
    depth = d;
}

// getDepth returns the number of cells in each dimension of the map
int ThreeDGridMap::getDepth() const
{
    return depth;
}