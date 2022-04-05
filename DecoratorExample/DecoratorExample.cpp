#include <iostream>

class DataSource
{
public:
    virtual std::string readData() = 0;
    virtual void saveData(std::string data) = 0;
};

class FileDataSource : public DataSource
{
public:
    FileDataSource(std::string filename) : filename_(filename) {}

    std::string readData() override { std::cout << "Read Data\n"; return {}; };
    void saveData(std::string data) override { std::cout << "Save Data\n"; };

private:
    std::string filename_;
};

class DataSourceDecorator : public DataSource
{
public:
    DataSourceDecorator(DataSource& data) : data_(data) {}

    virtual std::string readData() override
    {
        return data_.readData();
    }

    virtual void saveData(std::string data) override
    {
        data_.saveData(data);
    }

protected:
    DataSource& data_;
};

class EncryptedDataSourceDecorator : public DataSourceDecorator
{
public:
    EncryptedDataSourceDecorator(DataSource& data) : DataSourceDecorator(data) {}

    std::string readData() override final
    {
        EncryptData();
        return data_.readData();
    }

    void saveData(std::string data) override final
    {
        EncryptData();
        data_.saveData(data);
    }

private:
    void EncryptData() { std::cout << "Encrypt Data\n"; };
};

class CompressedDataSourceDecorator : public DataSourceDecorator
{
public:
    CompressedDataSourceDecorator(DataSource& data) : DataSourceDecorator(data) {}

    std::string readData() final
    {
        CompressData();
        return data_.readData();
    }

    void saveData(std::string data) final
    {
        CompressData();
        data_.saveData(data);
    }

private:
    void CompressData() { std::cout << "Compress Data\n"; };
};



int main()
{
    // Simple usage
    FileDataSource fileDataSource("exampleFile");
    fileDataSource.saveData("exampleData");
    std::cout << "\n\n";

    // Usage of decorator which extend functionality with encryption
    EncryptedDataSourceDecorator encryptedFileDataSourceDecorator(fileDataSource);
    encryptedFileDataSourceDecorator.saveData("exampleData");
    std::cout << "\n\n";

    // Usage of decorator which extend functionality with encryption and compression
    CompressedDataSourceDecorator compressedFileDataSourceDecorator(encryptedFileDataSourceDecorator);
    compressedFileDataSourceDecorator.saveData("exampleData");
}

