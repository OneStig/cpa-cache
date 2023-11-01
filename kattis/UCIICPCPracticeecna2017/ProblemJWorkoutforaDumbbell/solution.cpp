#include <bits/stdc++.h>

using namespace std;

struct JimEntry {
	long long use;
	long long recov;
};

struct MachineEntry {
	long long use;
	long long recov;
	long long start;
};

int main() {

	vector<JimEntry> jim;

	vector<MachineEntry> machines;

	for (long long i = 0; i < 10; i++) {
		JimEntry entry;

		cin >> entry.use >> entry.recov;

		jim.push_back(entry);
	}

	for (long long i = 0; i < 10; i++) {
		MachineEntry entry;
		cin >> entry.use >> entry.recov >> entry.start;

		machines.push_back(entry);
	}

	long long currtime = 0;
	for (long long i = 0; i < 3; i++) {
		for (long long j = 0; j < 10; j++) {
			MachineEntry& machine = machines[j];
			JimEntry& jimm = jim[j];

			if (machine.start > currtime) {
				machine.start = max(machine.start, currtime + jimm.use);
				currtime += jimm.use + jimm.recov;
				continue;
			}

			long long timeUserHad = currtime - machine.start;
			long long fullRoundCount = timeUserHad / (machine.use + machine.recov);
			long long fullRoundEnd = machine.start + fullRoundCount * (machine.use + machine.recov);

			long long newTime = fullRoundEnd + machine.use;

			if (newTime > currtime) {
				currtime = newTime + jimm.use + jimm.recov;
				machine.start = max(newTime + machine.recov, newTime + jimm.use);
			}
			else {
				currtime += jimm.use + jimm.recov;
				machine.start = max(newTime + machine.recov, currtime - jimm.recov);
			}
		}
	}

	std::cout << currtime - jim[9].recov << std::endl;

	return 0;

}
