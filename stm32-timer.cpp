namespace genericTimer {

	int clkHz = 8E6;

	void initHardware() {
		target::SYSTICK.RVR.setRELOAD(clkHz / 100L);
		target::SYSTICK.CVR.setCURRENT(0);
		target::SYSTICK.CSR.setTICKINT(1);
		target::SYSTICK.CSR.setCLKSOURCE(1);
		target::SYSTICK.CSR.setENABLE(1);
	}

}

void interruptHandlerSysTick() {
	applicationEvents::schedule(genericTimer::eventId);
}
