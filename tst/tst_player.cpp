#include <gtest/gtest.h>
#include "../src/player.h"

TEST(PlayerTestCase, ConstructorTest1)
{
    Player player(movementDirection::MOVING_UP, "Marcelo");
    EXPECT_EQ(player.getName(), "Marcelo");
    EXPECT_EQ(player.getActivePieces(), 8);

}


