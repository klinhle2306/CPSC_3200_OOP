using Microsoft.VisualStudio.TestTools.UnitTesting;
using P1;
/*
 * Linh Le
 * Revision date: 4/5/2022
 * Unit testing P1
*/

namespace P1UnitTest
{
    [TestClass]
    public class UnitTestP1
    {
        [TestMethod]
        public void testingMove()
        {
            gridFlea g1 = new gridFlea(0, 0, 0);
            g1.move(1);
            Assert.AreEqual(g1.getXPosition(), 1);
        }

        [TestMethod]
        public void testMode()
        {
            gridFlea g1 = new gridFlea(10, 2, 3);
            g1.move(9);
            g1.isActive();
            g1.isEnergeticMode();
            g1.isPermDeactivate();
            Assert.IsFalse(g1.isActive());
            Assert.IsFalse(g1.isEnergeticMode());
            Assert.IsTrue(g1.isPermDeactivate());
        }
    }
}