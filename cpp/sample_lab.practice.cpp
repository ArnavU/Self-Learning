#include <iostream>
using namespace std;

class InvalidFeeException {
    string message;

    public:
    InvalidFeeException(const string& msg) : message(msg) {}
    const string& getMessage() { return message; }
};

enum Consultation {
    EXIT,
    GENERAL_CONSULTATION,
    SPECIALIST_CONSULTATION,
    DIAGNOSTIC_CONSULTATION
};

class Appointment {
    string patientName, mobileNo;
    int patientId;

    protected:
    double totalBill;
    string consultationType;

    public:
    Appointment() : patientName(""), mobileNo(""), consultationType(""), patientId(0) {}
    Appointment(string patientName, string mobileNo, string consultationType, int patientId) : patientName(patientName), mobileNo(mobileNo), consultationType(consultationType), patientId(patientId) {}

    virtual void acceptRecord() {
        cout<<"Enter details: "<<endl;
        cout<<"Patient name: ";
        cin>>this->patientName;
        cout<<"Mobile no: ";
        cin>>this->mobileNo;
        cout<<"Patient id: ";
        cin>>patientId;
    }

    virtual void displayRecord() {
        cout<<"\nAppointment summary: "<<endl;
        cout<<"Consultation type: "<<consultationType<<endl;
        cout<<"Patient: "<<patientName<<endl;
        cout<<"Mobile no: "<<mobileNo<<endl;
        cout<<"Patient id: "<<patientId<<endl;
    }


    void setPatientName(string name) { patientName = name; }
    void setMobileNo(string mobileNo) { this->mobileNo = mobileNo; }
    void setConsultationType(string consultationType) { this->consultationType = consultationType; }
    void setPatientId(int patientId) { this->patientId = patientId; }
    string getPatientName() { return patientName; }
    string getMobileNo() { return mobileNo; }
    string getConsultationType() { return consultationType; }

    virtual void calculateTotalBill() = 0;
    virtual void displayBill() = 0; 
    
    virtual ~Appointment() {}
};

class GeneralConsultation : public Appointment{
    string doctorName;
    double consultationFee;
    static const int gst;

    public: 
    // TODO: CONSTRUCTOR
    GeneralConsultation(string consultationType) : doctorName(""), consultationFee(0.0) { Appointment::consultationType = consultationType; }
    GeneralConsultation(string patientName, string mobileNo, string consultationType, int patientId, string doctorName, double consultationFee) : Appointment(patientName, mobileNo, consultationType, patientId), doctorName(doctorName), consultationFee(consultationFee) {}

    string getDoctorName() { return doctorName; }
    double getConsultationFee() { return consultationFee; }
    void setDoctorName(string doctorName) { this->doctorName = doctorName; }
    void setConsultationFee(double consultationFee) { this->consultationFee = consultationFee; }

    void acceptRecord() {
        Appointment::acceptRecord();
        cout<<"Doctor name: ";
        cin>>this->doctorName;
        cout<<"Consultation Fee";
        int fee;
        cin>>fee;
        if(fee<0) {
            throw InvalidFeeException("Invalid input! Consultation Fee/Price cannot be negative.");
        } else {
            this->consultationFee = fee;
        }
    }

    void displayRecord() {
        Appointment::displayRecord();
        cout<<"Doctor name: "<<doctorName<<endl;
        cout<<"Consultation Fee: "<<consultationFee<<endl;
        displayBill();
    }

    void calculateTotalBill() {
        double totalBill = 0;
        totalBill = consultationFee + (gst/100.0)*consultationFee;
        Appointment::totalBill = totalBill;
    }
    void displayBill() {
        cout<<"Your total bill(General Consultaton): "<<totalBill<<endl;
    }
};
const int GeneralConsultation :: gst = 5;

class SpecialistConsultation : public Appointment {
    string doctorName, specialization;
    double consultationFee;
    static const int gst;

    public:
    SpecialistConsultation(string consultationType) { Appointment::consultationType = consultationType; }

    string getDoctorName() { return doctorName; }
    string getSpecialization() { return specialization; }
    double getConsultationFee() { return consultationFee; }
    void setDoctorName(string doctorName) { this->doctorName = doctorName; }
    void setSpecialization(string specialization) { this->specialization = specialization; }
    void setConsultationFee(double consultationFee) { this->consultationFee = consultationFee; }

    void acceptRecord() {
        Appointment::acceptRecord();
        cout<<"Doctor name: ";
        cin>>this->doctorName;
        cout<<"Specialization: ";
        cin>>this->specialization;
        cout<<"Consultation fee: ";
        int fee;
        cin>>fee;
        if(fee<0) {
            throw InvalidFeeException("Invalid input! Consultation Fee/Price cannot be negative.");
        } else {
            this->consultationFee = fee;
        }
    }

    void displayRecord() {
        Appointment::displayRecord();
        cout<<"Doctor name: "<<doctorName<<endl;
        cout<<"Specialization: "<<specialization<<endl;
        cout<<"Consultation fee: "<<consultationFee<<endl;
        this->displayBill();
    }
    

    void calculateTotalBill() {
        double totalBill = 0;
        totalBill = consultationFee + (gst/100.0)*consultationFee;
        Appointment::totalBill = totalBill;
    }
    void displayBill() {
        cout<<"Your total bill(General Consultaton): "<<totalBill<<endl;
    }
};
const int SpecialistConsultation :: gst = 10;

class Test {
    string testName;
    double price;

    public: 
    Test() : testName(""), price(0.0) {}
    Test(string testName, double price) : testName(testName), price(price) {}
    void setTestName(string testName) { this->testName = testName; }
    void setPrice(double price) { this->price = price; }
    string getTestName() { return this->testName; }
    double getPrice() { return this->price; }
    void displayTest() {
        cout<<"Test name: "<<testName<<endl;
        cout<<"Test price: "<<price<<endl;
    }
};

class DiagnosticConsultation : public Appointment {
    string doctorName;
    double consultationFee;
    int testSize;
    Test** tests;
    static const int gst;

    public:
    DiagnosticConsultation(string consultationType) { Appointment::consultationType = consultationType; Appointment::totalBill = 0; }
    void setDoctorName(string doctorName) { this->doctorName = doctorName; }
    void setConsultationFee(double consultationFee) { this->consultationFee = consultationFee; }
    string getDoctorName() { return doctorName;  }
    double getConsultationFee() { return consultationFee; }

    void acceptRecord() {
        Appointment::acceptRecord();
        cout<<"Doctor name: ";
        cin>>this->doctorName;
        cout<<"Consultation fee: ";
        int fee;
        cin>>fee;
        if(fee<0) {
            throw InvalidFeeException("Invalid input! Consultation Fee/Price cannot be negative.");
        } else {
            this->consultationFee = fee;
        }
        setTests();
    }

    void displayRecord() {
        Appointment::displayRecord();
        cout<<"Doctor name: "<<doctorName<<endl;
        cout<<"Consultation fee: "<<consultationFee<<endl;
        showTest();
        displayBill();
    }

    void setTests() {
        cout<<"Enter test details: "<<endl;
        cout<<"Enter no. of tests: ";
        cin>>this->testSize;
        tests = new Test*[this->testSize];

        for(int i=0; i<this->testSize; i++) {
            string testName;
            double price;
            cout<<"Enter test name: ";
            cin>>testName;
            cout<<"Enter test price: ";
            cin>>price;
            tests[i] = new Test(testName, price);            
        }
    }

    void showTest() {
        cout<<"Displaying all test: "<<endl;
        for(int i=0; i<testSize; i++) {
            tests[i]->displayTest();
        }
    }

    void calculateTotalBill() {
        double totalBill = 0;
        totalBill = consultationFee + (gst/100.0)*consultationFee;
        Appointment::totalBill += totalBill;
        for(int i=0; i<testSize; i++) {
            Appointment::totalBill += tests[i]->getPrice();
        }
    }
    void displayBill() {
        cout<<"Your total bill(General Consultaton): "<<totalBill<<endl;
    }

    ~DiagnosticConsultation() {
        if(tests) {
            cout<<"Destructor called.\n";
            for(int i=0; i<testSize; i++) {
                delete tests[i];
                tests[i] = NULL;
            }
            delete[] tests;
        }
    }
};
const int DiagnosticConsultation :: gst = 12;

int menuList() {
    int choice;
    cout<<"\n0. Exit."<<endl;
    cout<<"1. General Consultation."<<endl;
    cout<<"2. Specialist Consultation."<<endl;
    cout<<"3. Diagnostic Consultation."<<endl;
    cin>>choice;
    return choice;
}

class AppointmentFactory {
    public:
    static Appointment* getInstance(Consultation choice) {
        Appointment* ap = NULL;
        switch (choice) {
            case GENERAL_CONSULTATION:
                ap = new GeneralConsultation("General Consultation"); // upcasting
                break;
            case SPECIALIST_CONSULTATION:
                ap = new SpecialistConsultation("Specialist Consultation");
                break;
            case DIAGNOSTIC_CONSULTATION:
                ap = new DiagnosticConsultation("Diagnostic Consultation");
                break;
        }
        return ap;
    }
};


int main() {
    int choice;
    Appointment* ap;
    while((choice = menuList()) != 0) {
        try {
            switch(choice) {
                case GENERAL_CONSULTATION: 
                    ap = ::AppointmentFactory::getInstance(GENERAL_CONSULTATION);
                    break;
                case SPECIALIST_CONSULTATION:
                    ap = ::AppointmentFactory::getInstance(SPECIALIST_CONSULTATION);
                    break;
                case DIAGNOSTIC_CONSULTATION:
                    ap = ::AppointmentFactory::getInstance(DIAGNOSTIC_CONSULTATION);
                    break;
                    
            }
            if(ap!=nullptr) {    
                ap->acceptRecord();
                ap->calculateTotalBill();
                ap->displayRecord();
                delete ap;
                ap = nullptr;
            }
        } catch(InvalidFeeException &ex) {
            cout<<"InvalidFeeException: "<<ex.getMessage()<<endl;
        } catch(...) {
            cout<<"Exception occured"<<endl;
        }
    }
        
    return 0;
}