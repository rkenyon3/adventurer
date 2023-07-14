pipeline {
	agent {
		docker { image 'kitware/cmake' }
	}
	stages{
		stage('Build') {
			steps {
				sh 'echo "test"'
			}
		}
	}
}
