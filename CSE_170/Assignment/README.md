## Problem Description

You are tasked with building an interactive program called GeoExplorer that helps users analyze and explore a list of real-world places (such as parks, schools, markets, and hospitals) based on their geographic coordinates and type. Each place has a name, latitude, longitude, and a type (e.g., "School", "Market").

Your program should:
- Allow users to add new places to the system.
- Find the nearest place to a given location.
- Find the nearest place of a specific type to a given location.
- Show all places within a certain radius from a location.
- Group places by their type and display them.
- Find and display the two places that are farthest apart.
- Calculate and display the geographic center (centroid) of all places.

The program should be menu-driven, user-friendly, and provide clear prompts and outputs for each operation. It should use the Haversine formula to calculate distances between points on the Earth.

---

## Classes

### GeoPoint
Represents a real-world place with the following attributes:
- **name**: The name of the place.
- **latitude**: The latitude coordinate.
- **longitude**: The longitude coordinate.
- **type**: The type/category of the place (e.g., School, Market).

### GeoSystem
Manages a collection of GeoPoint objects and provides the following methods:
- **add_place(point)**: Add a new GeoPoint to the system.
- **find_nearest(lat, lon)**: Find the nearest place to the given latitude and longitude.
- **find_nearest_of_type(lat, lon, type_)**: Find the nearest place of the specified type to the given location.
- **find_within_radius(lat, lon, radius_km)**: Return all places within the given radius (in km) from the location.
- **group_by_type()**: Group all places by their type and return as a dictionary.
- **find_farthest_pair()**: Find and return the two places that are farthest apart.
- **center_point()**: Calculate and return the geographic center (centroid) of all places.

---

## Use This Function for Distance

```python
import math
def haversine(lat1, lon1, lat2, lon2):
    R = 6371
    dlat = math.radians(lat2 - lat1)
    dlon = math.radians(lon2 - lon1)
    a = math.sin(dlat/2)**2 + math.cos(math.radians(lat1)) \
        * math.cos(math.radians(lat2)) * math.sin(dlon/2)**2
    return R * 2 * math.asin(math.sqrt(a))
```

---

## Sample Data

```python
places = [
    GeoPoint("Central Park", 40.7851, -73.9683, "Park"),
    GeoPoint("City Hospital", 40.7401, -73.9902, "Hospital"),
    GeoPoint("Union Market", 40.7347, -74.0027, "Market"),
    GeoPoint("Green School", 40.7218, -73.9977, "School"),
    GeoPoint("Sunrise School", 40.7295, -73.9854, "School"),
]
```

---

## Menu Interface

When running the program, users should see:

```
GeoExplorer Menu:
1. Add a new place
2. Find nearest place to a location
3. Find nearest place of a specific type
4. Show all places within radius
5. Group places by type
6. Show two farthest places
7. Show center point
8. Exit
Enter your choice:
```

---

## Sample Input & Output

### Example Session

```
GeoExplorer Menu:
1. Add a new place
2. Find nearest place to a location
3. Find nearest place of a specific type
4. Show all places within radius
5. Group places by type
6. Show two farthest places
7. Show center point
8. Exit
Enter your choice: 1
Enter name: River Park
Enter latitude: 40.7500
Enter longitude: -73.9800
Enter type: Park
Place added!

Enter your choice: 2
Enter latitude: 40.7300
Enter longitude: -73.9900
Nearest place: City Hospital (40.7401, -73.9902, Hospital)

Enter your choice: 3
Enter latitude: 40.7300
Enter longitude: -73.9900
Enter type: School
Nearest School: Sunrise School (40.7295, -73.9854)

Enter your choice: 4
Enter latitude: 40.7300
Enter longitude: -73.9900
Enter radius (km): 2
Places within 2 km:
- City Hospital (Hospital)
- Union Market (Market)
- Green School (School)
- Sunrise School (School)

Enter your choice: 5
Grouped by type:
Park: Central Park, River Park
Hospital: City Hospital
Market: Union Market
School: Green School, Sunrise School

Enter your choice: 6
Farthest places: Central Park <-> Union Market (Distance: 3.1 km)

Enter your choice: 7
Center point: (40.7435, -73.9874)

Enter your choice: 8
Exiting GeoExplorer. Goodbye!
```

---

## Calculation Details

### How to Calculate the Center Point (Centroid)
- The center point (geographic centroid) is the average of all latitudes and all longitudes of the places in the system.
- Formula:
    - `center_latitude = (sum of all latitudes) / (number of places)`
    - `center_longitude = (sum of all longitudes) / (number of places)`
- Example:
    - If you have 3 places with latitudes 40.0, 41.0, 42.0 and longitudes -73.0, -74.0, -75.0:
        - `center_latitude = (40.0 + 41.0 + 42.0) / 3 = 41.0`
        - `center_longitude = (-73.0 + -74.0 + -75.0) / 3 = -74.0`

