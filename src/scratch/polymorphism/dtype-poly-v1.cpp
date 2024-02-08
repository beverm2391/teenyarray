class Dtype {
    public:
        virtual ~Dtype() {} // virtual destructor

        // define a pure virtual function
        virtual void convertType(Dtype *newtype) = 0; 
    
    // other ops as needed ...
};

class Float32 : public Dtype {
    public:
        void convertType(Dtype* newtype) override {
    }
};
