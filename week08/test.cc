#include "gtest/gtest.h"
#include "car_builder.h"
#include "car.h"
#include "H_parts_factory.h"
#include "K_parts_factory.h"

class HPartsFactoryTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class KPartsFactoryTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

TEST_F(HPartsFactoryTest, HCarTest1) {
    HPartsFactory* H_parts_factory = HPartsFactory::GetInstance();
    CarBuilder builder(H_parts_factory);
    Car* car = builder.CreateDoor()
        .CreateWheel()
        .CreateRoof()
        .SetColor("black")
        .Build();
    EXPECT_EQ(car->GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,black)");
}

TEST_F(HPartsFactoryTest, HCarTest2) {
    HPartsFactory* H_parts_factory = HPartsFactory::GetInstance();
    CarBuilder builder(H_parts_factory);
    Car* car1 = builder.CreateWheel().Build();
    EXPECT_EQ(car1->GetSpec(), "Car([H]Wheel,blue)");
    Car* car2 = builder.CreateDoor().CreateRoof().Build();
    EXPECT_EQ(car2->GetSpec(), "Car([H]Door,[H]Roof,blue)");
}

TEST_F(HPartsFactoryTest, HCarTest3) {
    HPartsFactory* H_parts_factory = HPartsFactory::GetInstance();
    CarBuilder builder(H_parts_factory);
    ASSERT_DEATH(builder.CreateDoor().CreateDoor(), "Duplicated Parts retain:Door");
    ASSERT_DEATH(builder.CreateWheel().CreateRoof().CreateWheel(), "Duplicated Parts retain:Wheel");
    ASSERT_DEATH(builder.CreateWheel().CreateRoof().CreateRoof(), "Duplicated Parts retain:Roof");
}

TEST_F(HPartsFactoryTest, HCarTest4) {
    HPartsFactory* H_parts_factory = HPartsFactory::GetInstance();
    CarBuilder builder(H_parts_factory);
    Car* car = builder.CreateDoor()
        .CreateWheel()
        .CreateRoof()
        .SetColor("black")
        .Build();
    Car* car_copy = car;
    EXPECT_EQ(car_copy->GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,black)");
}

TEST_F(HPartsFactoryTest, HCarTest5) {
    HPartsFactory* H_parts_factory = HPartsFactory::GetInstance();
    CarBuilder builder(H_parts_factory);
    Car* car = builder.SetColor("blue").Build();
    EXPECT_EQ(car->GetSpec(), "Car(blue)");
}

TEST_F(KPartsFactoryTest, KCarTest1) {
    KPartsFactory* K_parts_factory = KPartsFactory::GetInstance();
    CarBuilder builder(K_parts_factory);
    Car* car = builder.CreateDoor()
        .CreateWheel()
        .CreateRoof()
        .SetColor("black")
        .Build();
    EXPECT_EQ(car->GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,black)");
}

TEST_F(KPartsFactoryTest, KCarTest2) {
    KPartsFactory* K_parts_factory = KPartsFactory::GetInstance();
    CarBuilder builder(K_parts_factory);
    Car* car1 = builder.CreateRoof().Build();
    EXPECT_EQ(car1->GetSpec(), "Car([K]Roof,blue)");
    Car* car2 = builder.CreateDoor().CreateRoof().Build();
    EXPECT_EQ(car2->GetSpec(), "Car([K]Door,[K]Roof,blue)");
}

TEST_F(KPartsFactoryTest, KCarTest3) {
    KPartsFactory* K_parts_factory = KPartsFactory::GetInstance();
    CarBuilder builder(K_parts_factory);
    ASSERT_DEATH(builder.CreateDoor().CreateDoor(), "Duplicated Parts retain:Door");
    ASSERT_DEATH(builder.CreateWheel().CreateRoof().CreateWheel(), "Duplicated Parts retain:Wheel");
    ASSERT_DEATH(builder.CreateWheel().CreateRoof().CreateRoof(), "Duplicated Parts retain:Roof");
}

TEST_F(KPartsFactoryTest, KCarTest4) {
    KPartsFactory* K_parts_factory = KPartsFactory::GetInstance();
    CarBuilder builder(K_parts_factory);
    Car* car = builder.CreateDoor()
        .CreateWheel()
        .CreateRoof()
        .SetColor("black")
        .Build();
    Car* car_copy = car;
    EXPECT_EQ(car_copy->GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,black)");
}

TEST_F(KPartsFactoryTest, KCarTest5) {
    KPartsFactory* K_parts_factory = KPartsFactory::GetInstance();
    CarBuilder builder(K_parts_factory);
    Car* car = builder.SetColor("blue").Build();
    EXPECT_EQ(car->GetSpec(), "Car(blue)");
}
