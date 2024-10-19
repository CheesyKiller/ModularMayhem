export module BlenderObject_ShapeKey;

export import BlenderObject_ShapeKeyFrame;

export import <string>;
export import <vector>;

export struct ShapeKey {
	std::string name;
	std::vector<ShapeKeyframe> keyframes;
};